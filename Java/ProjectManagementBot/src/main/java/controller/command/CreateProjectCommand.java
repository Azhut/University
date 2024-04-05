package controller.command;

import model.Deadline;
import model.Project;
import controller.Facade;
import view.response.Response;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collections;

/**
 * Команда создания проекта
 */
public class CreateProjectCommand extends Command {

    public CreateProjectCommand(ArrayList<String> argsList, String requestUserId) {
        super(argsList, requestUserId);
    }

    @Override
    public Response perform() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy");
        LocalDate start = LocalDate.parse(getArgsList().get(1), formatter);
        LocalDate end = LocalDate.parse(getArgsList().get(2), formatter);
        Project project = new Project(requestUserId, getArgsList().get(0), new Deadline(start, end), getArgsList().get(3));
        return new Response(Facade.createProject(project), new ArrayList<>(Collections.singletonList(requestUserId)));
    }
}
