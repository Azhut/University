package controller.command;

import view.response.Response;

import java.util.ArrayList;

public class DeleteQuestionCommand extends Command{
    public DeleteQuestionCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        return null;
    }
}
