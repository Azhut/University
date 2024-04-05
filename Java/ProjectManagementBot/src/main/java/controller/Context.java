package controller;

import controller.command.Commands;
import view.request.Username;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Контекст контроллера:
 * state - состояние (EXECUTING/LISTENING)
 * command - выполняемая команда
 * iteration - итерация (какой параметр для команды ожидается от пользователя)
 * args - аргументы, заполненные пользователем
 * params - параметры выполняемой команды
 */
public class Context {
    private final HashMap<String, SessionState> usernameSessionStateHashMap;
    private State state;
    private Commands command;
    private int iteration;
    private ArrayList<Param> params;
    private final ArrayList<String> args;
    public Context(State state, Commands command, int iteration, ArrayList<String> args, ArrayList<Param> params) {
        this.state = state;
        this.command = command;
        this.iteration = iteration;
        this.args = args;
        this.params = params;
        this.usernameSessionStateHashMap = new HashMap<String, SessionState>();
    }

    /**
     * Добавление аргумента
     */

    public void addArg(String arg) {
        args.add(arg);
    }

    /**
     * Перевод контекста к ожиданию команды от пользователя
     */
    public void resetContextToListening(){
        state = State.LISTENING;
        resetContext();
    }

    /**
     * "Обнуление" атрибутов
     */
    private void resetContext() {
        command = Commands.NULL;
        iteration = 0;
        args.clear();
        params.clear();
    }
    /**
     * Перевод контекста к началу выполнения команды
     * параметры подтягиваются из компонента module
     */
    public void startExecutingCommand(Commands command) {
        this.state = State.EXECUTING;
        this.command = command;
        this.iteration = 0;
        args.clear();
        params = Facade.getParamsByCommand(command);
    }

    /**
     * Инкремент итератора
     */
    public void incrementIterator() {
        iteration += 1;
    }

    public Commands getCommand() {
        return command;
    }

    public int getIteration() {
        return iteration;
    }
    public ArrayList<Param> getParams() {
        return params;
    }

    public ArrayList<String> getArgs() {
        return args;
    }

    public HashMap<String, SessionState> getUsernameSessionStateHashMap() {
        return usernameSessionStateHashMap;
    }
    public void putSessionStateByUsername(Username username, SessionState sessionState) {
        usernameSessionStateHashMap.put(username.getUsername(), sessionState);
    }

    public SessionState getSessionStateByUsername(Username username) {
        SessionState sessionState = usernameSessionStateHashMap.get(username.getUsername());
        System.out.println(sessionState);
        if (sessionState == null) {
            return SessionState.NO_PROJECT;
        }
        return sessionState;
    }

    public State getState() {
        return state;
    }
}
