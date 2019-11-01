/*
 * The MIT License
 *
 * Copyright 2019 Leonardo Vencovsky (https://github.com/LeoVen/).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package eep.as.leoven.forms;

import javax.servlet.http.HttpServletRequest;

import org.apache.struts.action.ActionErrors;
import org.apache.struts.action.ActionMapping;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class SelectTranslationActionForm extends org.apache.struts.action.ActionForm {

    int languageId1;
    String languageName1;

    int languageId2;
    String languageName2;

    /**
     *
     */
    public SelectTranslationActionForm() {
        super();
        // TODO Auto-generated constructor stub
    }

    /**
     * This is the action called from the Struts framework.
     *
     * @param mapping The ActionMapping used to select this instance.
     * @param request The HTTP Request we are processing.
     * @return
     */
    @Override
    public ActionErrors validate(ActionMapping mapping, HttpServletRequest request) {
        // Validation is done in the front-end
        return new ActionErrors();
    }

    public int getLanguageId1() {
        return languageId1;
    }

    public void setLanguageId1(int languageId1) {
        this.languageId1 = languageId1;
    }

    public String getLanguageName1() {
        return languageName1;
    }

    public void setLanguageName1(String languageName1) {
        this.languageName1 = languageName1;
    }

    public int getLanguageId2() {
        return languageId2;
    }

    public void setLanguageId2(int languageId2) {
        this.languageId2 = languageId2;
    }

    public String getLanguageName2() {
        return languageName2;
    }

    public void setLanguageName2(String languageName2) {
        this.languageName2 = languageName2;
    }

}
