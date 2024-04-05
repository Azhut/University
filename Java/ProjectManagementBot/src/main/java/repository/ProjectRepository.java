package repository;

import model.Project;
import repository.Entity.ProjectEntity;

import java.util.List;

public interface ProjectRepository {
    Project findById(int id);
    List<Project> findAll();
    void save(ProjectEntity project);
    void update(ProjectEntity  project);
    void delete(ProjectEntity  project);
}
