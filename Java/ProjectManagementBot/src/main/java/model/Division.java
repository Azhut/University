package model;

import java.util.ArrayList;

public class Division {
    private String name;
    private ArrayList<TeamMember> divisionMembers;
    private ArrayList<String> links;
    private ArrayList<Question> questions;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ArrayList<TeamMember> getDivisionMembers() {
        return divisionMembers;
    }

    public void setDivisionMembers(ArrayList<TeamMember> divisionMembers) {
        this.divisionMembers = divisionMembers;
    }

    public ArrayList<String> getLinks() {
        return links;
    }

    public void setLinks(ArrayList<String> links) {
        this.links = links;
    }

    public ArrayList<Question> getQuestions() {
        return questions;
    }

    public void setQuestions(ArrayList<Question> questions) {
        this.questions = questions;
    }

    public Division(String name, ArrayList<TeamMember> divisionMembers, ArrayList<String> links, ArrayList<Question> questions) {
        this.name = name;
        this.divisionMembers = divisionMembers;
        this.links = links;
        this.questions = questions;
    }
}
