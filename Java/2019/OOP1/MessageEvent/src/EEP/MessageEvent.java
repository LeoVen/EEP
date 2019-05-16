/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package EEP;

import java.util.EventObject;

/**
 *
 * @author lvenk
 */
public class MessageEvent extends EventObject {

    private String message;

    public MessageEvent(Object source) {
        super(source);
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

}
