<%-- 
    Document   : index.jsp
    Created on : 31/10/2019, 03:00:47
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="java.util.Set"%>
<%@page import="eep.as.leoven.controller.PageContentController"%>
<%@page import="eep.as.leoven.dao.LanguageDAO"%>
<%@page import="eep.as.leoven.vo.Language"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Prevent caching
    if (PageContentController.noCaching) {
        response.setDateHeader("Expires", 0);
    }

    Set<Language> languages = new LanguageDAO().getAll();
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/css/materialize.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="${pageContext.request.contextPath}/css/main.css" type="text/css" >
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum</title>
    </head>
    <body>
        <div class="centered-card">
            <div class="card">
                <div class="card-content">
                    <div class="index-page-content">
                        <div>
                            <span class="card-title">Welcome to Translatorum</span>
                            <p>Here you can create and manage your vocabulary. Create languages, create words and assign them to a certain language and associate two  There are 4 simple steps:</p>
                            <ol>
                                <li>Create two languages</li>
                                <li>Create a word for each language</li>
                                <li>Assign a translation between the two words</li>
                                <li>Build up your dictionary!</li>
                            </ol>
                            <br>
                            <div class="flex-space-between">
                                <a href="language.jsp" class="btn white orange-text">Languages</a>
                                <a href="javascript:selectLanguageModal()" class="modal-trigger btn white orange-text">Words</a>
                                <a href="javascript:selectTranslationModal()" class="btn white orange-text">Translations</a>
                            </div>
                            <br>
                            <a href="dictionary.jsp" class="btn white orange-text">Dictionary</a>
                        </div>
                        <div>
                            <p>Developers: Igor Prata, Leonardo Vencovsky, Yan Trevizam</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <!-- MODALS -->
        <!-- SELECT LANGUAGE -->
        <div id="selectLanguageModal" class="modal modal-fixed-footer">
            <div class="modal-content">
                <h4>Select Language</h4>
                <% if (languages.isEmpty()) { %>
                <p>Sorry, you haven't created any language yet. Please go to <a href="language.jsp">this</a> page to create one.</p>
                <% } else { %>
                <ul class="collection hover">
                    <% for (Language lang : languages) {%>
                    <a href="javascript:selectLanguageSelection(<%= lang.getId()%>, '<%= lang.getName()%>')" class="collection-item">
                        <span class="listingText"><%= lang.getName()%></span>
                    </a>
                    <% } %>
                </ul>
                <% }%>
                <div style="padding: 40px;"></div>
            </div>
            <div class="modal-footer">
                <html:form action="SelectLanguage">
                    <div class="flex-space-around">
                        <div class="row margin0">
                            <div class="col s2 margin0">
                                <html:text styleId="selectLanguageId" styleClass="margin0" name="SelectLanguageActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="selectLanguageName" styleClass="margin0" name="SelectLanguageActionForm" property="languageName"/>
                            </div>
                        </div>
                        <html:submit styleId="selectLanguageSubmit" value="Select" styleClass="btn blue"/>
                        <a href="#!" class="modal-close btn red">Cancel</a>
                    </div>
                </html:form>
            </div>
        </div>

        <!-- SELECT TRANSLATION LANGUAGES -->
        <div id="selectTranslationModal" class="modal modal-fixed-footer">
            <div class="modal-content">
                <h4>Select Translation Languages</h4>
                <% if (languages.isEmpty()) { %>
                <p>Sorry, you haven't created any language yet. Please go to <a href="language.jsp">this</a> page to create one.</p>
                <% } else if (languages.size() == 1) { %>
                <p>Sorry but to create a translation you must first create two languages. Please go to <a href="language.jsp">this</a> page to create another one.</p>
                <% } else { %>
                <ul class="collection hover">
                    <% for (Language lang : languages) {%>
                    <a href="javascript:selectTranslationSelection(<%= lang.getId()%>, '<%= lang.getName()%>')" class="collection-item">
                        <span class="listingText"><%= lang.getName()%></span>
                    </a>
                    <% } %>
                </ul>
                <% }%>
                <div style="padding: 40px;"></div>
            </div>
            <div class="modal-footer">
                <html:form action="SelectTranslation">
                    <div class="flex-space-around">
                        <div class="valign-wrapper">
                            <i class="material-icons">translate</i>
                        </div>
                        <div class="row margin0">
                            <div class="display-none">
                                <html:text styleId="selectLanguageId1" styleClass="margin0" name="SelectTranslationActionForm" property="languageId1"/>
                                <html:text styleId="selectLanguageId2" styleClass="margin0" name="SelectTranslationActionForm" property="languageId2"/>
                            </div>
                            <div class="col s6 margin0">
                                <html:text styleId="selectLanguageName1" styleClass="margin0" name="SelectTranslationActionForm" property="languageName1"/>
                            </div>
                            <div class="col s6">
                                <html:text styleId="selectLanguageName2" styleClass="margin0" name="SelectTranslationActionForm" property="languageName2"/>
                            </div>
                        </div>
                        <html:submit styleId="selectTranslationSubmit" value="Select" styleClass="btn blue"/>
                        <a href="#!" class="modal-close btn red">Cancel</a>
                    </div>
                </html:form>
            </div>
        </div>


        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
