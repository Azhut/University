package controller.command;

import controller.Facade;
import view.response.Response;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Команда вывода информации о боте
 */
public class HelpCommand extends Command{
    public HelpCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        return new Response(Facade.getHelp(), new ArrayList<>(Collections.singletonList(requestUserId)));
    }
}
