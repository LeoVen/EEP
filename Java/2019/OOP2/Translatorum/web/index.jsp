<%-- 
    Document   : CreateLanguage
    Created on : 24/10/2019, 02:08:04
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="eep.as.leoven.dao.LanguageDAO"%>
<%@page import="eep.as.leoven.vo.Language"%>
<%@page import="java.util.Set"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%-- <%@page errorPage="error.jsp" %> --%>

<%
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
        <div class="row flex-stretch">
            <div class="col s12 m4 l3 left-view">
                <html:errors/>
                <p>Available Languages</p>
                <ul class="collection">
                    <% for (Language language : languages) {%>
                    <li class="collection-item">
                        <%= language.getName()%>
                        <a href="javascript:deleteLangModal(<%= language.getId()%>, '<%= language.getName()%>')" class="secondary-content">
                            <i class="material-icons red-text">delete</i>
                        </a>
                        <a href="javascript:editLangModal(<%= language.getId()%>, '<%= language.getName()%>')" class="secondary-content">
                            <i class="material-icons blue-text">edit</i>
                        </a>
                    </li>
                    <% }%>
                </ul>
                <div class="center-align margin-bottom">
                    <a href="javascript:createLangModal()" class="btn green">
                        <i class="material-icons">add</i>
                    </a>
                </div>
            </div>
            <div class="col s12 m8 l9">
                <!-- TODO -->
            </div>
        </div>

        <!-- MODALS -->
        <div id="createLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Create Language</h4>
                    <html:form action="CreateLanguage">
                        <p class="error-message" id="createLanguageError"></p>
                        <html:text styleId="createLanguageName" name="CreateLanguageActionForm" property="languageName"/>
                        <html:submit styleId="createLanguageSubmit" value="Create" styleClass="btn"/>
                    </html:form>
                    <html:errors/>
                </div>
            </div>
            <div class="modal-footer">
                <a href="#!" class="modal-close btn-flat">Close</a>
            </div>
        </div>

        <div id="editLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Edit Language</h4>
                    <html:form action="UpdateLanguage">
                        <div class="row">
                            <p class="error-message" id="editLanguageError"></p>
                            <div class="col s2 margin0">
                                <html:text styleId="editLanguageId" name="UpdateLanguageActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <html:text styleId="editLanguageName" name="UpdateLanguageActionForm" property="languageName"/>
                            </div>
                        </div>
                        <html:submit styleId="editLanguageSubmit" value="Update" styleClass="btn"/>
                    </html:form>
                    <html:errors/>
                </div>
            </div>
            <div class="modal-footer">
                <a href="#!" class="modal-close btn-flat">Close</a>
            </div>
        </div>

        <div id="deleteLanguageModal" class="modal">
            <div class="modal-content">
                <div class="container">
                    <h4>Confirm Action</h4>
                    <p>Are you sure you want to delete this Language? </p>
                    <p>This action will delete all the words and translations associated with it.</p>
                    <html:form action="DeleteLanguage">
                        <div class="row">
                            <div class="col s2 margin0">
                                <html:text styleId="deleteLanguageId" name="DeleteLanguageActionForm" property="languageId"/>
                            </div>
                            <div class="col s10">
                                <input id="deleteLanguageName" type="text"/>
                            </div>
                        </div>
                        <html:submit value="Delete" styleClass="btn"/>
                    </html:form>
                    <html:errors/>
                </div>
            </div>
            <div class="modal-footer">
                <a href="#!" class="modal-close btn-flat">Close</a>
            </div>
        </div>
        <!-- END MODALS -->
        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
