package org.example;

import java.util.*;

public class QuestionBank {
    final private Map<String, String> questions;
    final private Random random;

    public QuestionBank() {
        random = new Random();
        questions = new HashMap<>();

        questions.put("Какой цвет у неба?", "Голубой");
        questions.put("Сколько часов в сутках?", "24");
        questions.put("Как тебя зовут?", "Егор");
        questions.put("В какой группе ты учишься", "МО-202");
    }

    public boolean checkAnswer(String question, String userAnswer) {
        String correctAnswer = questions.get(question);
        return userAnswer.trim().equalsIgnoreCase(correctAnswer);
    }

    public String getRandomQuestion() {
        int index = random.nextInt(questions.size());
        Object[] keys = questions.keySet().toArray();
        return (String) keys[index];
    }
}