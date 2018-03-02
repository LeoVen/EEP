/*
 *
 * Collections
 *
 */

import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;
import java.util.Collections;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;


public class CollectionsJava {

	public static void main(String[] args) {


		// ArrayList
		Date primeiro = new Date(2,11,2018);
		String nome = "Leonardo";

		//É um array list que só aceita a classe String
		ArrayList<String> nomonth = new ArrayList<String>();

		nomonth.add("Rafael");
		nomonth.add(nome);
		nomonth.add("Mauricio");

		System.out.println(nomonth.get(0));
		System.out.println(nomonth.get(1));

		ArrayList<Date> calendario = new ArrayList<Date>();

		calendario.add(primeiro);
		calendario.add(new Date(24,12,2018));
		calendario.add(new Date(24,12,2017));
		calendario.add(new Date( 9, 1,2016));
		calendario.add(new Date(24,12,2018));
		calendario.add(new Date(26, 4,2018));
		calendario.add(new Date(29, 2,2020));
		calendario.add(new Date(12,12,2012));

		Collections.sort(calendario);

		for (Date c : calendario) System.out.println(c.getStringDate());

		// List
		// Uma List permite valores repetidos
		List<String> nomes = new LinkedList<String>();

		// Mas se queremos uma lista de valores que nao podem repetir usamos um HashSet
		Set<String> titulos = new HashSet<String>();
		titulos.add("Titulo_01");
		titulos.add("Titulo_02");
		titulos.add("Titulo_01");

		// Perceba que valores repetidos são ignorados
		System.out.println("Tamanho do HashSet: " + titulos.size());

		// Mas e com a classe Date?
		Set<Date> callendar = new HashSet<Date>();
		callendar.add(new Date(24,12,2014)); // 1
		callendar.add(new Date(24,12,2017)); // 2
		callendar.add(new Date( 9, 1,2016)); // 3
		callendar.add(new Date(24,12,2018)); // 4
		callendar.add(new Date(26, 4,2018)); // 5
		callendar.add(new Date(29, 2,2020)); // 6
		callendar.add(new Date(12,12,2012)); // 7
		callendar.add(new Date(12, 1,2011)); // 8
		callendar.add(new Date(12,12,2012)); // Este será ignorado (isso só acontece com a implementação do hashCode)

		System.out.println("Tamanho do calendario: " + callendar.size());

		// Um map de string para conta. Ou seja, o identificador é a string e o conteúdo e Conta
		Map<String, Conta> contas = new HashMap<String, Conta>();

		// contas.put(chave, valor);
		contas.put("Gerente", new Conta("Marcos", 3665.87));
		contas.put("Diretor", new Conta("Richard", 5434.33));
		contas.put("Funcionario", new Conta("Jose", 998.63));
		contas.put("Funcionario", new Conta("Jose", 998.63)); // Não é adicionado pois repete Funcionario

		/*
		 * Pegando uma conta a partir de um valor (string no caso) e depois
		 * usando um método da classe que retorna o saldo
		 *
		 */
		System.out.println(contas.get("Gerente").getSaldo());
		System.out.println(contas.get("Funcionario").getSaldo());

		System.out.println("Tamanho do HashMap: " + contas.size());

		/*
		 * Ver também os seguintes métodos :
		 *
		 * Collections.reverse(List<?> list);
		 * Collections.rotate(List<?> list, int distance);
		 * Collections.shuffle(List<?> list);
		 *
		 */

	}

}

class Date implements Comparable<Date> {

	private int day;
    private int month;
    private int year;
    private String aux_day;
    private String aux_month;

    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;

        if (! isDateViavel(day, month, year)) {
            System.out.println("A Date " + formata() + " não existe!");
        }
    }

    public String formata() {
        return this.day+"/"+this.month+"/"+this.year;
    }

    public String getStringDate() {

        if (this.day < 10) {
            this.aux_day = "0";
        } else {
            this.aux_day = "";
        }
        if (this.month < 10) {
            this.aux_month = "0";
        } else {
            this.aux_month = "";
        }
        return this.aux_day + this.day + "/" + this.aux_month + this.month + "/" + this.year;
    }

    public boolean addDMY(int day, int month, int year) {
        if (isDateViavel(this.day + day, this.month + month, this.year + year)) {
            this.day += day;
            this.month += month;
            this.year += year;
            return true;
        } else {
            System.out.println("Invalid parameters");
            return false;
        }
    }

    private boolean isDateViavel(int day, int month, int year) {
        if (day <= 0 || month <= 0) {
            return false;
        }
        if (month > 12) {
            return false;
        }

        int ultimodayDomonth = 31; // por padrao são 31 days
        if (month == 4 || month == 6 || month == 9 || month == 11 ) {
            ultimodayDomonth = 30;
        } else if (month == 2) {
            ultimodayDomonth = 28;
            if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))){
                ultimodayDomonth = 29;
            }
        }
        if (day > ultimodayDomonth) {
            return false;
        }

        return true;
    }

    // Método criado para ajudar na comparação entre datas
    public int compareDate(Date o) {

    	if (this.year > o.year) return 1;
    	else if (this.year < o.year) return -1;
    	else {
    		if (this.month > o.month) return 1;
    		else if (this.month < o.month) return -1;
    		else {
    			if (this.day > o.day) return 1;
    			else if (this.day < o.day) return -1;
    			else return 0;
    		}
    	}
    }

    // Se retorna 1 é maior, se retorna -1 é menor e se retorna 0 é igual
    @Override
    public int compareTo(Date o) {
    	//throw new UnsupportedOperationException("Not supported yet.");
        return this.compareDate(o);
    }

    // Implementação de comparação com HashSet, assim não é possível colocar uma mesma data no HashSet
    @Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + day;
		result = prime * result + month;
		result = prime * result + year;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Date other = (Date) obj;
		if (day != other.day)
			return false;
		if (month != other.month)
			return false;
		if (year != other.year)
			return false;
		return true;
	}

}

class Conta {

	private String nome;
	private double saldo;

	public Conta(String nome) {
		this.nome = nome;
	}

	public Conta(String nome, double saldo) {
		this.nome = nome;
		this.saldo = saldo;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public String getNome() {
		return this.nome;
	}

	public double getSaldo() {
		return this.saldo;
	}

}