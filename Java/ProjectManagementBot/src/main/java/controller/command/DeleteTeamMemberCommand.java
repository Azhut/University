package controller.command;

import view.response.Response;

import java.util.ArrayList;

public class DeleteTeamMemberCommand extends Command
{
    public DeleteTeamMemberCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    /**
     * @return
     */
    @Override
    public Response perform() {
        return null;
    }
}
