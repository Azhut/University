package repository;

import model.Project;
import repository.Entity.ProjectEntity;

import java.sql.Timestamp;

public class MapperService {
    /**
     * Преобразует объект типа Project в объект типа ProjectEntity.
     *
     * @param project объект типа Project, который нужно преобразовать
     * @return объект типа ProjectEntity
     * @throws IllegalArgumentException если project или project.getDeadlines() равны null
     */
    public static ProjectEntity mapToProjectEntity(Project project) {
        if (project == null) {
            throw new IllegalArgumentException("Project cannot be null");
        }

        if (project.getDeadlines() == null) {
            throw new IllegalArgumentException("Project deadlines cannot be null");
        }

        ProjectEntity projectEntity = new ProjectEntity();
        projectEntity.setTitle(project.getProjectName());
        projectEntity.setDescription(project.getDescription());

        if (project.getDeadlines().getStart() == null || project.getDeadlines().getEnd() == null) {
            throw new IllegalArgumentException("Project start date and end date cannot be null");
        }

        projectEntity.setTimeStart(Timestamp.valueOf(project.getDeadlines().getStart().atStartOfDay()));
        projectEntity.setTimeEnd(Timestamp.valueOf(project.getDeadlines().getEnd().atStartOfDay()));

        return projectEntity;
    }
}