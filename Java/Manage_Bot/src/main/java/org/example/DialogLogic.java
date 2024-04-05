package org.example;

public class DialogLogic {
    final private QuestionBank questionBank;
    final private ConsoleLogic consoleLogic;

    public DialogLogic() {
        questionBank = new QuestionBank();
        consoleLogic = new ConsoleLogic();
    }

    private void showHelp() {
        System.out.println("Я чат-бот. Я задаю тебе очень легкие вопросы и проверяю  твои ответы.. Следующий вопрос...");

    }
    public void startDialog() {
        consoleLogic.displayMessage("Привет! Я чат-бот. Буду задавать тебе вопросы и оценивать твои ответы.");

        while (true) {
            String question = questionBank.getRandomQuestion();
            consoleLogic.displayMessage("Вопрос: " + question);

            String userAnswer = consoleLogic.getUserInput();

            boolean isAnswerCorrect = questionBank.checkAnswer(question, userAnswer);

            if ("/help".equalsIgnoreCase(userAnswer)) {
                showHelp();
                continue;
            }
            if (isAnswerCorrect) {
                consoleLogic.displayMessage("Правильный ответ!");
            } else {
                consoleLogic.displayMessage("Неправильный ответ");
            }

        }
    }
}