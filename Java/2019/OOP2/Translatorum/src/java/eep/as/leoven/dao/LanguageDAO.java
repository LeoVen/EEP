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
import java.util.Set;
import java.util.TreeSet;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class LanguageDAO {

    Session session;

    public LanguageDAO() {
        session = HibernateUtil.getSessionFactory().getCurrentSession();
    }

    /**
     * Returns a single instance of a {@link Language} by a matching id.
     *
     * @param id Id to be searched in the database.
     *
     * @return A single instance of a {@link Language} of the given id.
     */
    public Language get(int id) {
        return (Language) session.createQuery("from Language where id = " + id)
                .uniqueResult();
    }

    /**
     * Returns all languages currently created in the database.
     *
     * @return All languages in the database.
     */
    public Set<Language> getAll() {
        return new TreeSet(session.createQuery("from Language").list());
    }

    /**
     * Creates a new {@link Language}
     *
     * @param language new language to be created.
     */
    public void create(Language language) {
        Transaction transaction = session.beginTransaction();
        session.save(language);
        session.flush();
        transaction.commit();
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
        Transaction transaction = session.beginTransaction();
        session.update(language);
        session.flush();
        transaction.commit();
    }

    /**
     * Updates a language given an id and a name separately.
     *
     * @param id    The id of an existing {@link Language}
     * @param name  The new name of a {@link Language}
     */
    public void update(int id, String name, Set words) {
        Language language = new Language(id, name, words);
        update(language);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        session.close();
    }
}
