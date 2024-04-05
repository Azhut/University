package controller.command;

import view.response.Response;

import java.util.ArrayList;

/**
 * Команда для выполнения контроллером
 * command - исполняемая команда
 * argsList - аргументы команды
 * requestUserId - id человека, который запустил команду
 */

public abstract class Command {
    private final ArrayList<String> argsList;
    protected final String requestUserId;

    public Command(ArrayList<String> argsList, String requestUserId) {
        this.argsList = argsList;
        this.requestUserId = requestUserId;
    }

    /**
     * Выполняет команду со списком аргументов argsList
     * @return response - результат выполнения команды
     */
    public abstract Response perform();

    public ArrayList<String> getArgsList() {
        return argsList;
    }
}
