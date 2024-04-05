package model;

import java.time.LocalDate;

public class Deadline {

    private LocalDate start;

    public Deadline(LocalDate start, LocalDate end) {
        this.start = start;
        this.end = end;
    }

    private LocalDate end;

    public LocalDate getStart() {
        return start;
    }

    public void setStart(LocalDate start) {
        this.start = start;
    }

    public LocalDate getEnd() {
        return end;
    }

    public void setEnd(LocalDate end) {
        this.end = end;
    }
}
