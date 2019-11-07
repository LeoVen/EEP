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
package eep.as.leoven.dao;

import eep.as.leoven.util.DbConnection;
import eep.as.leoven.vo.Translation;
import eep.as.leoven.vo.Word;
import java.util.List;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class TranslationDAO {

    /**
     * Gets all translations from the database.
     *
     * @return A list containing all translations.
     */
    public List<Translation> getAll() {
        Session session = null;
        List<Translation> translations = null;
        try {
            session = DbConnection.getInstance().getSession();

            translations = session.createQuery("from Translation").list();

            session.flush();
        } catch (HibernateException e) {
            throw e;
        } finally {
        }

        return translations;
    }

    /**
     * Associates a translation between two words. The language id of each word
     * is necessary and the word id.
     *
     * @param word1 Word one from the translation.
     * @param word2 Word two from the translation.
     */
    public void create(Word word1, Word word2) {
        Session session = null;
        Transaction transaction = null;
        Translation translation = new Translation(0, word1, word2);
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.save(translation);
            session.flush();

            transaction.commit();
        } catch (HibernateException e) {
            if (transaction != null) {
                transaction.rollback();
            }
            throw e;
        } finally {
        }
    }
}
