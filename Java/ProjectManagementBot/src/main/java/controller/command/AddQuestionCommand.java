package controller.command;

import controller.Facade;
import model.Question;
import view.request.Username;
import view.response.Response;

import java.util.ArrayList;
import java.util.Collections;
/**
 * Команда добавления вопроса
 */
public class AddQuestionCommand extends Command{
    public AddQuestionCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        Question question = new Question(getArgsList().get(0), new Username(requestUserId));
        return new Response(Facade.addQuestion(question), new ArrayList<>(Collections.singletonList(requestUserId)));
    }
}
