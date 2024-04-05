package controller.command;

import controller.Facade;
import view.response.Response;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Команда запуска бота
 */
public class StartCommand extends Command{
    public StartCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        return new Response(Facade.getStartMessage(requestUserId), new ArrayList<>(Collections.singletonList(requestUserId)));
    }
}
