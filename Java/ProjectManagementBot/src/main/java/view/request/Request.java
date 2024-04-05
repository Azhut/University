package view.request;

/**
 * Запрос пользователя
 */
public class Request
{
    private final String request;
    private final String userId;
    private String username;
    public Request(String request, String userId, String username) {
        this.request = request;
        this.userId = userId;
        this.username = username;
    }
    public Request(String request) {
        this.request = request;
        this.userId = "";
    }

    /**
     * @return возвращает запрос пользователя
     */
    public String getRequest() {
        return request;
    }

    public String getUserId() {
        return userId;
    }

    public String getUsername() {return username;}
}