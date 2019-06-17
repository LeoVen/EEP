/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.model;

import java.awt.Component;
import java.sql.Date;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

/**
 *
 * @author lvenk
 */
public class ToDo {

    public int id;
    public String title;
    public String description;
    public String category;
    public Date due;

    public ToDo(int id, String title, String description, String category, Date due) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.category = category;
        this.due = due;
    }

    @Override
    public String toString() {
        return "(" + category + ") " + title + " " + description + " " + due;
    }
}
