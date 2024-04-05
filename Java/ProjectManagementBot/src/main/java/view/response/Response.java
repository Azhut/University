package view.response;

import java.util.ArrayList;

/**
 * Ответ на пользовательский запрос
 * response - текст ответа
 * responseUserIds - айди пользователей, которым вернётся ответ
 */
public class Response {
    private final String response;
    private final ArrayList<String> responseUserIds;

    private final RequestedTypes requestedType;

    public Response(String response, ArrayList<String> responseUserIds, RequestedTypes requestedType) {
        this.response = response;
        this.responseUserIds = responseUserIds;
        this.requestedType = requestedType;
    }
    public Response(String response, ArrayList<String> responseUserIds) {
        this.response = response;
        this.responseUserIds = responseUserIds;
        this.requestedType = RequestedTypes.TEXT;
    }
    public String getResponse() {
        return response;
    }
    public ArrayList<String> getResponseUserIds() {
        return responseUserIds;
    }

    public RequestedTypes getRequestedType() {
        return requestedType;
    }
}
