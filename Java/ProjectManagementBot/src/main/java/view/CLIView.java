package view;

import controller.Controller;
import view.request.Request;
import view.response.Response;

import java.util.Scanner;

/**
 * Вид в командной строке
 */
public class CLIView implements View {
    private final Controller controller;

    public CLIView(Controller controller) {
        this.controller = controller;
    }

    /**
     * startDialog - запуск диалога в командной строке
     */
    public void startDialog() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Привет! Я ProjectManagementBot! Введите ваш запрос:");
        while (true) {
            String input = scanner.nextLine();

            Request request = new Request(input, "", "");

            Response response = controller.handleWithResponse(request);

            System.out.println(response.getResponse());

            if (response.getResponse().equals("Работа бота завершена")) {
                break;
            }
        }
    }
}
