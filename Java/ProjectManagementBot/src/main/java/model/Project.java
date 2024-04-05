package model;


import java.util.ArrayList;

/**
 * Проект
 * projectName - название
 * deadlines - сроки
 * description - описание проекта
 */

public class Project {
    public Project(String teamleadUsername, String projectName, Deadline deadlines, String description) {
        this.teamleadUsername = teamleadUsername;
        this.projectName = projectName;
        this.deadlines = deadlines;
        this.description = description;
    }

    public String getProjectName() {
        return projectName;
    }

    public Deadline getDeadlines() {
        return deadlines;
    }

    public String getDescription() {
        return description;
    }

    public void setProjectName(String projectName) {
        this.projectName = projectName;
    }

    public void setDeadlines(Deadline deadlines) {
        this.deadlines = deadlines;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    private String teamleadUsername;
    private String projectName;
    private Deadline deadlines;
    private String description;
    private ArrayList<Division> divisions;

    public ArrayList<Division> getDivisions() {
        return divisions;
    }

    public void setDivisions(ArrayList<Division> divisions) {
        this.divisions = divisions;
    }

    public ArrayList<TeamMember> getMembers() {
        return members;
    }

    public void setMembers(ArrayList<TeamMember> members) {
        this.members = members;
    }

    private ArrayList<TeamMember> members;
}