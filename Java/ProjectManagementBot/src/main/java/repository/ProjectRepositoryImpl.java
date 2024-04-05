package repository;

import jakarta.persistence.criteria.CriteriaBuilder;
import jakarta.persistence.criteria.CriteriaQuery;
import jakarta.persistence.criteria.Root;
import model.Project;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import repository.Entity.ProjectEntity;

import java.util.List;

public class ProjectRepositoryImpl implements ProjectRepository {
    private SessionFactory sessionFactory;

    public ProjectRepositoryImpl() {
        this.sessionFactory = HibernateUtil.getSessionFactory();
    }

    @Override
    public Project findById(int id) {
        Session session = sessionFactory.openSession();
        Project project = session.get(Project.class, id);
        session.close();
        return project;
    }

    @Override
    public List<Project> findAll() {
        Session session = sessionFactory.openSession();
        CriteriaBuilder builder = session.getCriteriaBuilder();
        CriteriaQuery<Project> query = builder.createQuery(Project.class);
        Root<Project> root = query.from(Project.class);
        query.select(root);
        List<Project> projects = session.createQuery(query).getResultList();
        session.close();
        return projects;
    }

    @Override
    public void save(ProjectEntity project) {
        Session session = sessionFactory.openSession();
        session.getTransaction().begin();
        session.persist(project);
        session.getTransaction().commit();
        session.close();
    }

    @Override
    public void update(ProjectEntity  project) {
        Session session = sessionFactory.openSession();
        Transaction transaction = session.beginTransaction();
        session.update(project);
        transaction.commit();
        session.close();
    }

    @Override
    public void delete(ProjectEntity  project) {
        Session session = sessionFactory.openSession();
        Transaction transaction = session.beginTransaction();
        session.delete(project);
        transaction.commit();
        session.close();
    }
}