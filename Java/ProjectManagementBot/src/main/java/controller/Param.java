package controller;

import view.response.RequestedTypes;


/**
 * Параметры для команды
 * name - название
 * requestedTypes - запрашиваемый тип
 */
public class Param {
    private final String name;
    private final RequestedTypes requestedTypes;

    public Param(String name, RequestedTypes requestedTypes) {
        this.name = name;
        this.requestedTypes = requestedTypes;
    }

    public String getName() {
        return name;
    }

    public RequestedTypes getRequestedTypes() {
        return requestedTypes;
    }

}
