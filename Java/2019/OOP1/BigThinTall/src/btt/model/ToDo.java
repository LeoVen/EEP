package btt.model;

import java.util.Calendar;


public class ToDo {

    public int id;
    public String title;
    public String description;
    public String category;
    public Calendar due;

    public ToDo(int id, String title, String description, String category, Calendar due) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.category = category;
        this.due = due;
    }

    public static String normalizeStupidDate(Calendar c) {
        // I hate java dates
        int month = c.get(Calendar.MONTH) + 1;
        String m = "";
        if (month < 10) {
            m = "0" + month;
        } else {
            m = month + "";
        }
        String date = (c.get(Calendar.DAY_OF_MONTH) + 1) + "/" + m + "/" + c.get(Calendar.YEAR);
        return date;
    }

    @Override
    public String toString() {
        String date = ToDo.normalizeStupidDate(due);
        String padding = "______________________________________________________________________________________________";
        return "<html> <h2>" + title + "</h2> <p>" + description + "</p> <p style='text-align: right;'>" + date + "</p>" + padding;
    }
}
