package model;

import view.request.Username;

public class Question {
    private String question;
    private Username asker;

    public Question(String question, Username asker) {
        this.question = question;
        this.asker = asker;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public Username getAsker() {
        return asker;
    }

    public void setAsker(Username asker) {
        this.asker = asker;
    }
}
