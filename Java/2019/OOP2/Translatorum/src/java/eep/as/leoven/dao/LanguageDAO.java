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

import eep.as.leoven.util.HibernateUtil;
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
     * Returns a single instance of a {@link Language} by a matching id.
     *
     * @param id Id to be searched in the database.
     *
     * @return A single instance of a {@link Language} of the given id.
     */
    public Language get(int id) {
        Session session = null;
        Language language = null;
        try {
            session = HibernateUtil.getSessionFactory().openSession();

            language = (Language) session.createQuery("from Language where id = " + id).uniqueResult();

            session.flush();
        } catch (HibernateException e) {
            throw e;
        } finally {
            if (session != null) {
                session.close();
            }
        }

        return language;
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
            session = HibernateUtil.getSessionFactory().openSession();
            List<Language> languages = session.createQuery("from Language").list();

            session.flush();

            ret = new TreeSet<>((l1, l2) -> l1.getName().compareTo(l2.getName()));
            ret.addAll(languages);
        } catch (HibernateException e) {
            throw e;
        } finally {
            if (session != null) {
                session.close();
            }
        }

        return ret;
    }

    /**
     * Creates a new {@link Language}
     *
     * @param language new language to be created.
     */
    public void create(Language language) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = HibernateUtil.getSessionFactory().openSession();
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
     * Creates a new {@link Language} a language name.
     *
     * @param name New language name.
     */
    public void create(String name) {
        Language language = new Language(0, name);
        create(language);
    }

    /**
     * Updates a given language using a new one. Note that is must have a valid
     * id.
     *
     * @param language Representation of a modified language.
     */
    public void update(Language language) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = HibernateUtil.getSessionFactory().openSession();
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
     * Updates a language given an id and a name separately.
     *
     * @param id The id of an existing {@link Language}
     * @param name The new name of a {@link Language}
     */
    public void update(int id, String name) {
        Language language = new Language(id, name, new TreeSet());
        update(language);
    }

    /**
     * Updates a language given an id and a name separately with all of its
     * current words mapped.
     *
     * @param id The id of an existing {@link Language}
     * @param name The new name of a {@link Language}
     * @param words Current words of the given language
     */
    public void update(int id, String name, Set words) {
        Language language = new Language(id, name, words);
        update(language);
    }

    /**
     * Deletes a language by a given id.
     *
     * @param id Language id to be deleted
     */
    public void delete(int id) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = HibernateUtil.getSessionFactory().openSession();
            transaction = session.beginTransaction();

            session.delete(new Language(id, ""));
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
