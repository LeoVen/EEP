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
import eep.as.leoven.vo.Language;
import eep.as.leoven.vo.Word;
import java.util.List;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class WordDAO {

    public WordDAO() {
    }

    /**
     * Gets all words that are from a given language.
     *
     * @param language The language to be matched for each word.
     *
     * @return Returns a list of words that are part of the specified language.
     */
    public List<Word> getByLanguage(Language language) {
        Session session = null;
        List<Word> words = null;
        try {
            session = DbConnection.getInstance().getSession();

            words = (List<Word>) session.createQuery("from Word as w where w.language = " + language.getId()).list();

            if (words.isEmpty()) {
                words = null;
            }

            session.flush();
        } catch (HibernateException e) {
            throw e;
        } finally {
        }

        return words;
    }

    /**
     * Creates a word from a language reference and its text string.
     *
     * @param language The word's language reference.
     * @param text The text that represents a word.
     */
    public void create(Language language, String text) {
        Session session = null;
        Transaction transaction = null;
        Word word = new Word(language, text);
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.save(word);
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

    /**
     * Updates a given word. The word must contains at least its id, its word
     * text and a language with an id.
     *
     * @param word The word to be updated in the database.
     */
    public void update(Word word) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.update(word);
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

    /**
     * Deletes a word from the database. The word must contain at least its id.
     *
     * @param word A word to be deleted from the database.
     */
    public void delete(Word word) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.delete(word);
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
