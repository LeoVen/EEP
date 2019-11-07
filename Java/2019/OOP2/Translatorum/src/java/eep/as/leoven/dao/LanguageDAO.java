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
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class LanguageDAO {

    public LanguageDAO() {
    }

    /**
     * Returns all languages currently created in the database.
     *
     * @return All languages in the database.
     */
    public Set<Language> getAll() {
        Session session = null;
        TreeSet<Language> ret = null;
        try {
            session = DbConnection.getInstance().getSession();
            List<Language> languages = session.createQuery("from Language").list();

            session.flush();

            ret = new TreeSet<>((l1, l2) -> l1.getName().compareTo(l2.getName()));
            ret.addAll(languages);
        } catch (HibernateException e) {
            throw e;
        } finally {
        }

        return ret;
    }

    /**
     * Creates a new language.
     *
     * @param language New language to be created.
     */
    public void create(Language language) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.save(language);
            session.flush();

            transaction.commit();
        } catch (HibernateException e) {
            if (transaction != null) {
                transaction.rollback();
            }
            throw e;
        } finally {
            if (session != null) {
                session.close();
            }
        }
    }

    /**
     * Updates a given language using a new one. It must have a valid id.
     *
     * @param language Representation of a modified language.
     */
    public void update(Language language) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.update(language);
            session.flush();

            transaction.commit();
        } catch (HibernateException e) {
            if (transaction != null) {
                transaction.rollback();
            }
            throw e;
        } finally {
            if (session != null) {
                session.close();
            }
        }
    }

    /**
     * Deletes a language from database. At least its id is required.
     *
     * @param language Language to be deleted.
     */
    public void delete(Language language) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.delete(language);
            session.flush();

            transaction.commit();
        } catch (HibernateException e) {
            if (transaction != null) {
                transaction.rollback();
            }
            throw e;
        } finally {
            if (session != null) {
                session.close();
            }
        }
    }

}
