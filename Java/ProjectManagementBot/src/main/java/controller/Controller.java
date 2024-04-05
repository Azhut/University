package controller;

import controller.command.*;
import view.request.Request;
import view.request.Username;
import view.response.Response;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Контроллер
 */
public class Controller {

    private final Context context;

    /**
     * Конструктор контроллера
     */
    public Controller() {
        this.context = new Context(State.LISTENING, Commands.NULL, 0, new ArrayList<>(), new ArrayList<>());
    }

    /**
     * Выполнение "быстрой" команды
     * @param command - выполняемая команда
     * @return response - результат
     */
    private Response executeQuickCommand(Commands command, Request request) {
        String requestUserId = request.getUserId();
        Username requestUsername = new Username(request.getUsername());
        if (command == Commands.EXIT) {
            ExitCommand exitCommand = new ExitCommand(context.getArgs(), requestUserId);
            return exitCommand.perform();
        }
        else if (command == Commands.HELP) {
            HelpCommand helpCommand = new HelpCommand(context.getArgs(), requestUserId);
            return helpCommand.perform();
        }
        else if (command == Commands.START) {
            StartCommand startCommand = new StartCommand(context.getArgs(), requestUserId);
            return startCommand.perform();
        }
        else if (command == Commands.DELETE_PROJECT) {
            if (context.getSessionStateByUsername(requestUsername) == SessionState.HAS_PROJECT) {
                DeleteProjectCommand deleteProjectCommand = new DeleteProjectCommand(context.getArgs(), requestUserId);
                context.putSessionStateByUsername(requestUsername, SessionState.NO_PROJECT);
                return deleteProjectCommand.perform();
            }
            else {
                return new Response("Данная команда не доступна", new ArrayList<>(Collections.singletonList(requestUserId)));
            }

        }
        return null;
    }

    /**
     * Выполнение "долгой" команды
     * @param arg - аргумент команды
     * @return response
     */
    private Response executeLongCommand(String arg, Request request) {
        String requestUserId = request.getUserId();
        Username requestUsername = new Username(request.getUsername());
        int iteration = context.getIteration();
        if (iteration > 0) {
            context.addArg(arg);
        }

        if (iteration < context.getParams().size()) {
            context.incrementIterator();
            return new Response("Введите " + context.getParams().get(iteration).getName(), new ArrayList<>(Collections.singletonList(requestUserId)), context.getParams().get(iteration).getRequestedTypes());
        }

        ArrayList<String> args = new ArrayList<>(context.getArgs());

        if (context.getCommand() == Commands.CREATE_PROJECT) {
            CreateProjectCommand createProjectCommand = new CreateProjectCommand(args, requestUserId);
            context.resetContextToListening();
            context.putSessionStateByUsername(requestUsername, SessionState.HAS_PROJECT);
            return createProjectCommand.perform();
        }
        else if (context.getCommand() == Commands.ADD_QUESTION) {
            AddQuestionCommand addQuestionCommand = new AddQuestionCommand(args, requestUserId);
            context.resetContextToListening();
            return addQuestionCommand.perform();
        }
        else if (context.getCommand() == Commands.ADD_TEAM_MEMBER) {
            AddTeamMemberCommand addTeamMemberCommand = new AddTeamMemberCommand(args, requestUserId);
            context.resetContextToListening();
            return addTeamMemberCommand.perform();
        }

        return new Response("Нет такого параметра!", new ArrayList<>(Collections.singletonList(requestUserId)));
    }

    /**
     * Возвращает response с сообщением о невозможности выполнения команды
     * @param requestUserId - id юзера, которому надо отправить response
     * @return response
     */
    private Response commandNotAvailableMessage(String requestUserId) {
        return new Response("Данная команда не доступна", new ArrayList<>(Collections.singletonList(requestUserId)));
    }

    /**
     * Начало выполнения "долгой" команды
     * @param command - выполняемая команда
     * @return response
     */
    private Response startLongCommand(Commands command, Request request) {
        String requestUserId = request.getUserId();
        Username requestUsername = new Username(request.getUsername());
        if (command == Commands.CREATE_PROJECT) {
            if (context.getSessionStateByUsername(requestUsername) == SessionState.NO_PROJECT) {
                context.startExecutingCommand(command);
                Response firstCommandResponse = executeLongCommand("", request);
                return new Response("Начинается создание проекта\n" + firstCommandResponse.getResponse(), new ArrayList<>(Collections.singletonList(requestUserId)));
            }
            else {
                return commandNotAvailableMessage(requestUserId);
            }
        }
        else if (command == Commands.ADD_QUESTION) {
            if (context.getSessionStateByUsername(requestUsername) == SessionState.HAS_PROJECT) {
                context.startExecutingCommand(command);
                Response firstCommandResponse = executeLongCommand("", request);
                return new Response("Добавление вопроса:\n" + firstCommandResponse.getResponse(), new ArrayList<>(Collections.singletonList(requestUserId)));
            }
            else {
                return commandNotAvailableMessage(requestUserId);
            }
        }
        else if (command == Commands.ADD_TEAM_MEMBER) {
            if (context.getSessionStateByUsername(requestUsername) == SessionState.HAS_PROJECT) {
                context.startExecutingCommand(command);
                Response firstCommandResponse = executeLongCommand("", request);
                return new Response("Добавление участника:\n" + firstCommandResponse.getResponse(), new ArrayList<>(Collections.singletonList(requestUserId)));
            }
            else {
                return commandNotAvailableMessage(requestUserId);
            }
        }
        return null;
    }
    /**
     * Обрабатывает запрос и дожидается ответа.
     * @param request запрос пользователя.
     * @return ответ на запрос пользователя.
     */

    public Response handleWithResponse(Request request) {

        String requestString = request.getRequest();

        String requestUserId = request.getUserId();

        if (requestString.isEmpty()) {
            return new Response("Запрос отсутствует", new ArrayList<>(Collections.singletonList(requestUserId)));
        }

        if (context.getState() == State.LISTENING) {
            if (requestString.charAt(0) == '/') {
                switch (requestString) {
                    case "/exit":
                        return executeQuickCommand(Commands.EXIT, request);
                    case "/help":
                        return executeQuickCommand(Commands.HELP, request);
                    case "/create_project":
                        return startLongCommand(Commands.CREATE_PROJECT, request);
                    case "/add_question":
                        return startLongCommand(Commands.ADD_QUESTION, request);
                    case "/add_team_member":
                        return startLongCommand(Commands.ADD_TEAM_MEMBER, request);
                    case "/start":
                        return executeQuickCommand(Commands.START, request);
                    case "/delete_project":
                        return executeQuickCommand(Commands.DELETE_PROJECT, request);
                    default:
                        return new Response("Неизвестная команда", new ArrayList<>(Collections.singletonList(requestUserId)));
                }
            }
            else {
                return new Response("Запрос не является командой", new ArrayList<>(Collections.singletonList(requestUserId)));
            }
        }
        else if (context.getState() == State.EXECUTING) {
            return executeLongCommand(request.getRequest(), request);
        }

        return new Response("", new ArrayList<>(Collections.singletonList(requestUserId)));
    }
}
