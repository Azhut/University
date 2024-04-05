package controller;

import controller.command.Commands;
import model.Project;
import model.Question;
import model.TeamMember;
import repository.MapperService;
import repository.ProjectRepository;
import repository.ProjectRepositoryImpl;
import view.response.RequestedTypes;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Facade - обработчик запросов
 */
public abstract class Facade {
    /**
     * Добавляет проект в базу данных
     * @param project - проект
     * @return string с сообщением о создании нового проекта
     */


    static public String createProject(Project project) {
        //сохранение в базу данных

        ProjectRepository projectRepository = new ProjectRepositoryImpl();
        projectRepository.save(MapperService.mapToProjectEntity(project));
        return "Проект создан!\nНазвание проекта: " + project.getProjectName() + "\nСроки: " + project.getDeadlines().getStart() + " - " + project.getDeadlines().getEnd()  + "\nОписание: " + project.getDescription();
    }

    static public String addTeamMember(TeamMember teamMember) {
        // добавление в бд
        return "Участник добавлен в проект!";
    }

    static public String addQuestion(Question question) {
        // добавление в бд
        return "Вопрос добавлен!";
    }

    static public String deleteProject(String teamleadUserId) {
        // добавление в бд

        return "Проект удалён!";
    }

    /**
     * Отправляет сообщение о выходе из бота
     * @return string с сообщением о выходе
     */
    static public String exitBot() {
        return "Работа бота завершена";
    }

    /**
     * Отправляет сообщение с информацией о боте
     * @return string сообщение с перечислением доступных команд
     */
    static public String getHelp() {
        return "Я - бот для работы с проектом. Вот список моих команд:\n " +
                "/start - запуск бота\n " +
                "/create_project - создание проекта \n " +
                "/delete_project - удаление проекта\n" +
                "/add_question - добавление вопроса\n" +
                "/delete_question - удаление вопроса\n" +
                "/add_team_member - добавление участника\n" +
                "/delete_team_member - добавление участника\n" +
                "/exit - завершение работы бота";
    }

    /**
     * Возвращает параметры, которые надо заполнить
     * @param command - команда, в соответствии с которой надо вернуть параметры
     * @return список параметров
     */
    static public ArrayList<Param> getParamsByCommand(Commands command) {
        ArrayList<Param> response = new ArrayList<>();
        if (command == Commands.CREATE_PROJECT) {
            Param[] params = {new Param("название", RequestedTypes.TEXT), new Param("начало", RequestedTypes.DATE), new Param("окончание", RequestedTypes.DATE), new Param("описание", RequestedTypes.TEXT)};

            response.addAll(new ArrayList<>(Arrays.asList(params)));
        }
        else if (command == Commands.ADD_TEAM_MEMBER) {
            Param[] params = {new Param("username", RequestedTypes.TEXT), new Param("роль", RequestedTypes.TEXT)};
            response.addAll(new ArrayList<>(Arrays.asList(params)));
        }
        else if (command == Commands.ADD_QUESTION) {
            Param[] params = {new Param("вопрос", RequestedTypes.TEXT)};
            response.addAll(new ArrayList<>(Arrays.asList(params)));
        }
        return response;
    }


    /**
     * Приветственное сообщение
     * @return String - сообщение "Привет!..." + (в будущем) внутренняя авторизация
     */
    public static String getStartMessage(String id) {
        return "\"Привет! Я ProjectManagementBot! Ваши проекты: .... Ваша должность: .... Введите ваш запрос:\"";
    }
}
