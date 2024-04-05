package view;

import controller.Controller;
import io.github.cdimascio.dotenv.Dotenv;
import org.telegram.telegrambots.bots.TelegramLongPollingBot;
import org.telegram.telegrambots.meta.TelegramBotsApi;
import org.telegram.telegrambots.meta.api.methods.send.SendMessage;
import org.telegram.telegrambots.meta.api.methods.updatingmessages.DeleteMessage;
import org.telegram.telegrambots.meta.api.objects.CallbackQuery;
import org.telegram.telegrambots.meta.api.objects.Update;
import org.telegram.telegrambots.meta.api.objects.Message;
import org.telegram.telegrambots.meta.api.objects.User;
import org.telegram.telegrambots.meta.api.objects.replykeyboard.InlineKeyboardMarkup;
import org.telegram.telegrambots.meta.api.objects.replykeyboard.buttons.InlineKeyboardButton;
import org.telegram.telegrambots.meta.exceptions.TelegramApiException;
import org.telegram.telegrambots.updatesreceivers.DefaultBotSession;
import view.request.Request;
import view.response.RequestedTypes;
import view.response.Response;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.TextStyle;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;

/**
 * Вид в телеграмме
 * controller - контроллер
 * currentMonth - текущий месяц (для календаря)
 * lastMessageId - id последнего сообщения
 */

public class TelegramView extends TelegramLongPollingBot implements View {
    private LocalDate currentMonth = LocalDate.now();
    private Integer lastMessageId;
    private final HashMap<String, Controller> usersBase;

    public TelegramView() {
        this.usersBase = new HashMap<>();
    }

    /**
     * Получение имени бота
     * @return string название бота
     */
    @Override
    public String getBotUsername() {
        return Dotenv.load().get("BOT_USERNAME");
    }

    /**
     * Получения токена для работы с ботом
     * @return string токен, содержащийся в .env
     */
    @Override
    public String getBotToken() {
        return Dotenv.load().get("BOT_TOKEN");
    }

    /**
     * Реакция на действия пользователя
     * @param update - действие пользователя
     */
    @Override
    public void onUpdateReceived(Update update) {
        if (update.hasMessage() && update.getMessage().hasText()) {
            Message msg = update.getMessage();
            User user = msg.getFrom();
            Long id = user.getId();
            String username = user.getUserName();
            Request request = new Request(msg.getText(), id.toString(), user.getUserName());

            if (!usersBase.containsKey(username)) {
                usersBase.put(username, new Controller());
            }

            Response response = usersBase.get(username).handleWithResponse(request);

            ArrayList<String> responseIds = response.getResponseUserIds();

            sendTextOnResponse(response, responseIds);


        } else if (update.hasCallbackQuery()) {
            String chatId = update.getCallbackQuery().getMessage().getChatId().toString();
            String data = update.getCallbackQuery().getData();
            if ("prev_month".equals(data)) {
                deletePreviousCalendar(chatId);
                currentMonth = currentMonth.minusMonths(1);
                sendCalendarRequest(chatId);
            } else if ("next_month".equals(data)) {
                deletePreviousCalendar(chatId);
                currentMonth = currentMonth.plusMonths(1);
                sendCalendarRequest(chatId);
            } else {
                CallbackQuery query = update.getCallbackQuery();
                User user = query.getFrom();
                Long id = user.getId();
                LocalDate selectedDate = LocalDate.parse(data, DateTimeFormatter.ISO_DATE);

                String formattedDate = selectedDate.format(DateTimeFormatter.ofPattern("dd.MM.yyyy"));
                deletePreviousCalendar(chatId);

                sendText(chatId, "Вы выбрали дату: " + formattedDate);

                Request request = new Request(formattedDate, id.toString(), user.getUserName());
                String username = user.getUserName();
                if (!usersBase.containsKey(username)) {
                    usersBase.put(username, new Controller());
                }

                Response response = usersBase.get(username).handleWithResponse(request);
                ArrayList<String> responseIds = response.getResponseUserIds();

                sendTextOnResponse(response, responseIds);
            }
        }
    }

    private void sendTextOnResponse(Response response, ArrayList<String> responseIds) {
        if (response.getRequestedType() == RequestedTypes.TEXT) {
            for (String responseId : responseIds) {
                sendText(responseId, response.getResponse());
            }
        }
        else if (response.getRequestedType() == RequestedTypes.DATE) {
            for (String responseId : responseIds) {
                sendText(responseId, response.getResponse());
                sendCalendarRequest(responseId);
            }
        }
    }

    /**
     * @param chatId - id чата
     * отправляет пользователю календарь для выбора даты
     */
    private void sendCalendarRequest(String chatId) {

        InlineKeyboardMarkup inlineKeyboardMarkup = new InlineKeyboardMarkup();
        List<List<InlineKeyboardButton>> keyboard = new ArrayList<>();

        List<InlineKeyboardButton> monthSwitchRow = new ArrayList<>();

        InlineKeyboardButton backButton = InlineKeyboardButton.builder().text("<< Пред. месяц").callbackData("prev_month").build();
        InlineKeyboardButton currMonthButton = InlineKeyboardButton.builder().text(currentMonth.format(DateTimeFormatter.ofPattern("MMMM yyyy"))).callbackData("ignore").build();
        InlineKeyboardButton nextButton = InlineKeyboardButton.builder().text("След. месяц >>").callbackData("next_month").build();

        monthSwitchRow.add(backButton);
        monthSwitchRow.add(currMonthButton);
        monthSwitchRow.add(nextButton);

        keyboard.add(monthSwitchRow);

        List<InlineKeyboardButton> daysOfWeekRow = new ArrayList<>();
        for (DayOfWeek dayOfWeek : DayOfWeek.values()) {
            InlineKeyboardButton day = InlineKeyboardButton.builder().text(dayOfWeek.getDisplayName(TextStyle.SHORT, Locale.ENGLISH)).callbackData("ignore").build();
            daysOfWeekRow.add(day);
        }
        keyboard.add(daysOfWeekRow);

        LocalDate firstDayOfMonth = currentMonth.withDayOfMonth(1);
        int daysInMonth = currentMonth.lengthOfMonth();

        int currentDayOfWeek = firstDayOfMonth.getDayOfWeek().getValue();

        List<InlineKeyboardButton> currentRow = new ArrayList<>();
        for (int i = 0; i < currentDayOfWeek - 1; i++) {
            InlineKeyboardButton month = InlineKeyboardButton.builder().text(" ").callbackData("ignore").build();

            currentRow.add(month);
        }

        for (int day = 1; day <= daysInMonth; day++) {
            LocalDate date = firstDayOfMonth.withDayOfMonth(day);

            InlineKeyboardButton button = new InlineKeyboardButton();
            button.setText(Integer.toString(day));
            button.setCallbackData(date.toString());
            currentRow.add(button);

            if (currentRow.size() == 7) {
                keyboard.add(currentRow);
                currentRow = new ArrayList<>();
            }
        }

        while (currentRow.size() < 7 && !currentRow.isEmpty()) {
            InlineKeyboardButton month = InlineKeyboardButton.builder().text(" ").callbackData("ignore").build();
            currentRow.add(month);
        }

        keyboard.add(currentRow);

        inlineKeyboardMarkup.setKeyboard(keyboard);

        SendMessage message = new SendMessage(chatId, "Выберите дату:");
        message.setReplyMarkup(inlineKeyboardMarkup);

        try {
            Message sentMessage = execute(message);
            lastMessageId = sentMessage.getMessageId();
        } catch (TelegramApiException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Удаляет календарь в сообщении по id
     * @param chatId - id чата
     */
    private void deletePreviousCalendar(String chatId) {
        if (lastMessageId != null) {
            DeleteMessage deleteMessage = new DeleteMessage(chatId, lastMessageId);
            try {
                execute(deleteMessage);
            } catch (TelegramApiException e) {
                throw new RuntimeException(e);
            }
        }
    }

    /**
     * Отправка сообщения
     * @param userId - id человека, которому отправляется сообщение
     * @param text - текст сообщения
     */
    private void sendText(String userId, String text){
        SendMessage sm = SendMessage.builder()
                .chatId(userId)
                .text(text).build();
        try {
            execute(sm);
        } catch (TelegramApiException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * startDialog - запуск диалога в телеграмме
     */
    @Override
    public void startDialog() {
        TelegramBotsApi botsApi;
        try {
            botsApi = new TelegramBotsApi(DefaultBotSession.class);
            botsApi.registerBot(this);
        } catch (TelegramApiException e) {
            throw new RuntimeException(e);
        }
    }
}