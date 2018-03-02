/*
 *
 * Classe pegada e editada da Alura
 *
 */

/**
 * Classe simples sobre data
 * @author Leonardo Vencovsky
 *
 */
public class Data {
    private int dia;
    private int mes;
    private int ano;
    private String aux_dia;
    private String aux_mes;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;

        if (! isDataViavel(dia, mes, ano)) {
            System.out.println("A data " + formata() + " não existe!");
        }
    }

    public String formata() {
        return this.dia+"/"+this.mes+"/"+this.ano;
    }

    /**
    * Um método simples que retorna a data formatada.
    *
    * @return Retorna uma string no formato dd/mm/aaaa.
    */
    public String getStringData() {

        if (this.dia < 10) {
            this.aux_dia = "0";
        } else {
            this.aux_dia = "";
        }
        if (this.mes < 10) {
            this.aux_mes = "0";
        } else {
            this.aux_mes = "";
        }
        return this.aux_dia + this.dia + "/" + this.aux_mes + this.mes + "/" + this.ano;
    }

    /**
    * Classe que adiciona meses, dias e anos. Não faz reajuste automatico.
    *
    * @param dia Quantos dias serão adicionados ou subtraídos
    * @param mes Quantos meses serão adicionados ou subtraídos
    * @param ano Quantos anos serão adicionados ou subtraídos
    *
    * @return Retorna verdadeiro se foi possível adicionar os valores à Data,
    *                 caso contrário retorna falso.
    */
    public boolean addDMY(int dia, int mes, int ano) {
        if (isDataViavel(this.dia + dia, this.mes + mes, this.ano + ano)) {
            this.dia += dia;
            this.mes += mes;
            this.ano += ano;
            return true;
        } else {
            System.out.println("Invalid parameters");
            return false;
        }
    }

    private boolean isDataViavel(int dia, int mes, int ano) {
        if (dia <= 0 || mes <= 0) {
            return false;
        }
        if (mes > 12) {
            return false;
        }

        int ultimoDiaDoMes = 31; // por padrao são 31 dias
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11 ) {
            ultimoDiaDoMes = 30;
        } else if (mes == 2) {
            ultimoDiaDoMes = 28;
            if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))){
                ultimoDiaDoMes = 29;
            }
        }
        if (dia > ultimoDiaDoMes) {
            return false;
        }

        return true;
    }
}