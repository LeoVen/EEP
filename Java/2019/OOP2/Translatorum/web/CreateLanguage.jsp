<%-- 
    Document   : CreateLanguage
    Created on : 24/10/2019, 02:08:04
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Create new Language</title>
    </head>
    <body>
        <h1>Create a new Language</h1>
        <html:form action="CreateLanguage">
            <p>Language Name</p>
            <br>
            <html:text name="CreateLanguageActionForm" property="languageName"/>
            <br>
            <html:submit value="Create"/>
        </html:form>
        <html:errors/>
    </body>
</html>
