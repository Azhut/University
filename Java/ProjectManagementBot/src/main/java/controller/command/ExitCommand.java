package controller.command;

import controller.Facade;
import view.response.Response;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Команда завершения работы бота
 */
public class ExitCommand extends Command{
    public ExitCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        return new Response(Facade.exitBot(), new ArrayList<>(Collections.singletonList(requestUserId)));
    }

    @Override
    public ArrayList<String> getArgsList() {
        return super.getArgsList();
    }
}
