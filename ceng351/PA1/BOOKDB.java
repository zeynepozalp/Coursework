/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ceng.ceng351.bookdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author ZEYNEP
 */
public class BOOKDB implements IBOOKDB{
    private static String user = "2237691"; // TODO: Your userName
    private static String password = "cf48cb4b"; //  TODO: Your password
    private static String host = "144.122.71.65"; // host name
    private static String database = "db2237691"; // TODO: Your database name
    private static int port = 8084; // port
    
    private Connection con;

    public BOOKDB() {
        // TODO Auto-generated constructor stub
    }
    
    @Override
    public void initialize() {
        String url = "jdbc:mysql://" + this.host + ":" + this.port + "/" + this.database;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            this.con =  DriverManager.getConnection(url, this.user, this.password);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        } 
    }
    
    @Override
    public int createTables() {
        int result;
        int numberofTablesInserted = 0;

        String queryCreateAuthorTable = "create table author (" + 
                                        "author_id int not null," + 
                                        "author_name varchar(60)," +
                                        "primary key (author_id))";
        String queryCreatePublisherTable = "create table publisher (" + 
                                        "publisher_id int not null," + 
                                        "publisher_name varchar(50)," +
                                        "primary key (publisher_id))";
        String queryCreateBookTable = "create table book (" + 
                                        "isbn char(13) not null," + 
                                        "book_name varchar(120)," +
                                        "publisher_id int not null," + 
                                        "first_publish_year char(4)," +
                                        "page_count int," +
                                        "category varchar(25)," + 
                                        "rating float," +
                                        "primary key (isbn),"+
                                        "foreign key (publisher_id) references publisher(publisher_id));";
        String queryCreateAuthorOfTable = "create table author_of (" + 
                                        "isbn char(13) not null," + 
                                        "author_id int not null," +
                                        "primary key (isbn,author_id),"+
                                        "foreign key (isbn) references book(isbn),"+
                                        "foreign key (author_id) references author(author_id))";
        String queryCreatePhw1Table = "create table phw1 (" + 
                                        "isbn char(13) not null," + 
                                        "book_name varchar(120)," +
                                        "rating float," +
                                        "primary key (isbn))" ;
        try {
            Statement statement = this.con.createStatement();

            //Author Table
            result = statement.executeUpdate(queryCreateAuthorTable);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();

            //Publisher Table
            result = statement.executeUpdate(queryCreatePublisherTable);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();

            //Book Table
            result = statement.executeUpdate(queryCreateBookTable);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();

            //Author_of Table
            result = statement.executeUpdate(queryCreateAuthorOfTable);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
            
        try {
            Statement statement = this.con.createStatement();

            //Phw1 Table
            result = statement.executeUpdate(queryCreatePhw1Table);
            numberofTablesInserted++;

            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        } 
        
        return numberofTablesInserted;
    }
    
    @Override
    public int dropTables(){
        int result;
        int numberofTablesDropped = 0;

        String queryDropAuthorTable = "drop table if exists author";
        String queryDropPublisherTable = "drop table if exists publisher";
        String queryDropBookTable = "drop table if exists book";
        String queryDropAuthorOfTable = "drop table if exists author_of";
        String queryDropPhw1Table = "drop table if exists phw1";

        try {
            Statement statement = this.con.createStatement();
            
            result = statement.executeUpdate(queryDropAuthorOfTable);
            numberofTablesDropped++;
            
            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();
            
            result = statement.executeUpdate(queryDropPhw1Table);
            numberofTablesDropped++;
            
            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();
            
            result = statement.executeUpdate(queryDropBookTable);
            numberofTablesDropped++;
            
            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        try {
            Statement statement = this.con.createStatement();
            
            result = statement.executeUpdate(queryDropAuthorTable);
            numberofTablesDropped++;
            
            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
            
        try {
            Statement statement = this.con.createStatement();
            
            result = statement.executeUpdate(queryDropPublisherTable);
            numberofTablesDropped++;
            
            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }    
        
        return numberofTablesDropped;
    }
    
    @Override
    public int insertAuthor(Author[] authors){
        int numberOfRowsInserted = 0;
        for(int i=0; i<authors.length; i++){
            int result = 0;

            String query = "insert into author values (" + 
                        authors[i].getAuthor_id()+ ",'" + 
                        authors[i].getAuthor_name().replaceAll("'", "''")+ "')";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                numberOfRowsInserted++;

                //Close
                st.close();

            } catch (SQLException e) {
                //e.printStackTrace();
                e.printStackTrace();
            }
        }
        return numberOfRowsInserted;
    }
    
    //book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
    //rating:float) REFERENCES publisher(publisher id)
    @Override
    public int insertBook(Book[] books){
        int numberOfRowsInserted = 0;
        for(int i=0; i<books.length; i++){
            int result = 0;

            String query = "insert into book values ('" + 
                        books[i].getIsbn()+ "','" + 
                        books[i].getBook_name().replaceAll("'", "''")+ "'," +
                        books[i].getPublisher_id()+ ",'" +
                        books[i].getFirst_publish_year().replaceAll("'", "''")+ "'," +
                        books[i].getPage_count()+ ",'" +
                        books[i].getCategory().replaceAll("'", "''")+ "'," +
                        books[i].getRating()+ ")";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                numberOfRowsInserted++;

                //Close
                st.close();

            } catch (SQLException e) {
                //e.printStackTrace();
                e.printStackTrace();
            }
        }
        return numberOfRowsInserted;
    }
    
    @Override
    public int insertPublisher(Publisher[] publishers){
        int numberOfRowsInserted = 0;
        for(int i=0; i<publishers.length; i++){
            int result = 0;

            String query = "insert into publisher values (" + 
                        publishers[i].getPublisher_id()+ ",'" +
                        publishers[i].getPublisher_name().replaceAll("'", "''")+ "')";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                numberOfRowsInserted++;

                //Close
                st.close();

            } catch (SQLException e) {
                //e.printStackTrace();
                e.printStackTrace();
            }
        }
        return numberOfRowsInserted;
    }
    
    @Override
    public int insertAuthor_of(Author_of[] author_ofs){
        int numberOfRowsInserted = 0;
        for(int i=0; i<author_ofs.length; i++){
            int result = 0;

            String query = "insert into author_of values ('" + 
                        author_ofs[i].getIsbn()+ "'," +
                        author_ofs[i].getAuthor_id()+ ")";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                numberOfRowsInserted++;

                //Close
                st.close();

            } catch (SQLException e) {
                //e.printStackTrace();
                e.printStackTrace();
            }
        }
        return numberOfRowsInserted;
    }
    
    //List isbn, first publish year, page count and publisher name of the books which have the maximum number of pages.
    //Order the results by isbn in ascending order.
    @Override
    public QueryResult.ResultQ1[] functionQ1(){
        ResultSet rs;

        String query = "select b.isbn, b.first_publish_year, b.page_count, p.publisher_name from book b, publisher p where b.publisher_id=p.publisher_id and b.page_count=(select max(page_count) from book) order by b.isbn;";

        QueryResult.ResultQ1[] res = new QueryResult.ResultQ1[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                String isbn = rs.getString("isbn");
                String fpy = rs.getString("first_publish_year");
                int page_count = rs.getInt("page_count");
                String publisher_name = rs.getString("publisher_name");

                QueryResult.ResultQ1 q1 = new QueryResult.ResultQ1(isbn,fpy,page_count,publisher_name);
                
                QueryResult.ResultQ1[] tmp = new QueryResult.ResultQ1[res.length+1];
                System.arraycopy(res, 0, tmp, 0, res.length);
                tmp[tmp.length - 1] = q1;
                res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return res;
    }
    
    @Override
    public QueryResult.ResultQ2[] functionQ2(int author_id1, int author_id2){
        ResultSet rs;

         String query = "select p.publisher_id as publisher_id, AVG(b.page_count) as avg "+
                        "from publisher p, book b "+
                        "where p.publisher_id=b.publisher_id and "+
                        "p.publisher_id in (select p2.publisher_id "+
                                            "from author_of a1, author_of a2, publisher p2, book b2 "+
                                            "where p2.publisher_id=b2.publisher_id and b2.isbn=a1.isbn and a1.isbn=a2.isbn and a1.author_id="+ author_id1 + " and  a2.author_id=" + author_id2 +") "+
                        "group by publisher_id "+
                        "order by publisher_id;";
                
        QueryResult.ResultQ2[] res = new QueryResult.ResultQ2[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                int publisher_id = rs.getInt("publisher_id");
                double avg = rs.getDouble("avg");

                QueryResult.ResultQ2 q2 = new QueryResult.ResultQ2(publisher_id, avg);
                
                QueryResult.ResultQ2[] tmp = new QueryResult.ResultQ2[res.length+1];
                System.arraycopy(res, 0, tmp, 0, res.length);
                tmp[tmp.length - 1] = q2;
                res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return res;
    }
    
    @Override
    public QueryResult.ResultQ3[] functionQ3(String author_name){
        ResultSet rs;

        String query = "select B.book_name, B.category, B.first_publish_year "+
                        "from book B, author_of AO, author A "+
                        "where A.author_name='"+author_name+"' and "+
                        "A.author_id=AO.author_id and "+
                        "AO.isbn=B.isbn and "+
                        "B.first_publish_year = (select min(B2.first_publish_year) "+
                                                "from book B2, author_of AO2 "+
                                                "where AO2.author_id=AO.author_id and "+
                                                "B2.isbn=AO2.isbn) "+
                        "order by B.book_name, B.category, B.first_publish_year;";
                
        QueryResult.ResultQ3[] res = new QueryResult.ResultQ3[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                String book_name = rs.getString("book_name");
                String category = rs.getString("category");
                String fpy = rs.getString("first_publish_year");

                QueryResult.ResultQ3 q = new QueryResult.ResultQ3(book_name,category,fpy);
                
                QueryResult.ResultQ3[] tmp = new QueryResult.ResultQ3[res.length+1];
                System.arraycopy(res, 0, tmp, 0, res.length);
                tmp[tmp.length - 1] = q;
                res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    @Override
    public QueryResult.ResultQ4[] functionQ4(){
        ResultSet rs;

        String query = "select distinct P.publisher_name, P.publisher_id, B.category "+
                        "from publisher P, book B "+
                        "where P.publisher_id=B.publisher_id and "+
                        "P.publisher_id in (select B2.publisher_id "+
                                            "from book B2 "+
                                            "group by B2.publisher_id "+
                                            "having count(*)>3 and avg(B2.rating)>3) "+
                        "order by P.publisher_id, B.category;";
                
        QueryResult.ResultQ4[] res = new QueryResult.ResultQ4[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                String publisher_name = rs.getString("publisher_name");
                int publisher_id = rs.getInt("publisher_id");
                String category = rs.getString("category");

                String[] tokens = publisher_name.split(" ");
                if(tokens.length>2){
                    QueryResult.ResultQ4 q = new QueryResult.ResultQ4(publisher_id, category);
                
                    QueryResult.ResultQ4[] tmp = new QueryResult.ResultQ4[res.length+1];
                    System.arraycopy(res, 0, tmp, 0, res.length);
                    tmp[tmp.length - 1] = q;
                    res=tmp;
                }
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    @Override
    public QueryResult.ResultQ5[] functionQ5(int author_id){
        ResultSet rs;

        String query = "select A.author_id, A.author_name "+
                        "from author A "+
                        "where  not exists (select B.publisher_id "+
					"from book B, author_of AO "+
					"where AO.isbn = B.isbn and AO.author_id = "+author_id+" and "+
					"not exists (select B2.publisher_id "+
								"from author_of AO2, book B2 "+
								"where AO2.isbn = B2.isbn and AO2.author_id=A.author_id and B2.publisher_id=B.publisher_id)) "+ 
                        "order by A.author_id;";
                
        QueryResult.ResultQ5[] res = new QueryResult.ResultQ5[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                int ai = rs.getInt("author_id");
                String an = rs.getString("author_name");

                    QueryResult.ResultQ5 q = new QueryResult.ResultQ5(ai,an);
                
                    QueryResult.ResultQ5[] tmp = new QueryResult.ResultQ5[res.length+1];
                    System.arraycopy(res, 0, tmp, 0, res.length);
                    tmp[tmp.length - 1] = q;
                    res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    //yanlış
    @Override
    public QueryResult.ResultQ6[] functionQ6(){
        ResultSet rs;

        String query = "select distinct ao.author_id, b.isbn "+
                        "from author_of ao, book b "+
                        "where ao.isbn=b.isbn and ao.author_id in "+
                        "(select distinct AO.author_id "+
                        "from author_of AO, book B, publisher P "+
                        "where AO.isbn=B.isbn and B.publisher_id=P.publisher_id "+
                        "and not exists (select * "+
                                        "from author_of AO2, book B2, publisher P2 "+ 
                                        "where AO2.isbn=B2.isbn and B2.publisher_id=P2.publisher_id "+ 
                                        "and AO2.author_id!=AO.author_id and P2.publisher_id=P.publisher_id)) "+
                        "order by ao.author_id, b.isbn;";
                
        QueryResult.ResultQ6[] res = new QueryResult.ResultQ6[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                int ai = rs.getInt("author_id");
                String isbn = rs.getString("isbn");

                    QueryResult.ResultQ6 q = new QueryResult.ResultQ6(ai,isbn);
                
                    QueryResult.ResultQ6[] tmp = new QueryResult.ResultQ6[res.length+1];
                    System.arraycopy(res, 0, tmp, 0, res.length);
                    tmp[tmp.length - 1] = q;
                    res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    @Override
    public QueryResult.ResultQ7[] functionQ7(double rating){
        ResultSet rs;

        String query = "select P.publisher_id, P.publisher_name "+
                        "from publisher P, book B "+
                        "where P.publisher_id=B.publisher_id "+
                        "and P.publisher_id in (select P2.publisher_id "+
			"			from publisher P2, book B2 "+
                        "                        where P2.publisher_id=B2.publisher_id and B2.category='Roman' "+
                        "                        group by P2.publisher_id "+
                        "                        having count(*)>1) "+
                        "group by P.publisher_id "+
                        "having avg(B.rating) > "+rating+" order by P.publisher_id;";
                
        QueryResult.ResultQ7[] res = new QueryResult.ResultQ7[0];
        
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                int pi = rs.getInt("publisher_id");
                String pn = rs.getString("publisher_name");

                    QueryResult.ResultQ7 q = new QueryResult.ResultQ7(pi,pn);
                
                    QueryResult.ResultQ7[] tmp = new QueryResult.ResultQ7[res.length+1];
                    System.arraycopy(res, 0, tmp, 0, res.length);
                    tmp[tmp.length - 1] = q;
                    res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    @Override
    public QueryResult.ResultQ8[] functionQ8(){
        ResultSet rs;

        String update = "insert into phw1(isbn,book_name,rating) "+
                        "select B.isbn, B.book_name, B.rating "+
                        "from book B "+
                        "where B.rating = (select min(B2.rating) "+
			"		from book B2 "+
                        "                where B2.book_name = B.book_name "+
                        "                group by B2.book_name "+
                        "                having count(B2.isbn)>1); ";
        String query = "select * from phw1 order by isbn; ";
                
        QueryResult.ResultQ8[] res = new QueryResult.ResultQ8[0];
        
        try {
            Statement st = this.con.createStatement();
            st.executeUpdate(update);
            rs = st.executeQuery(query);	
            
            while(rs.next()){
                //First call method next() to make the first row current row.

                String isbn = rs.getString("isbn");
                String book_name = rs.getString("book_name");
                double rating = rs.getDouble("rating");

                    QueryResult.ResultQ8 q = new QueryResult.ResultQ8(isbn, book_name, rating);
                
                    QueryResult.ResultQ8[] tmp = new QueryResult.ResultQ8[res.length+1];
                    System.arraycopy(res, 0, tmp, 0, res.length);
                    tmp[tmp.length - 1] = q;
                    res=tmp;
            }

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;
    }
    
    @Override
    public double functionQ9(String keyword){
        ResultSet rs;
        double sum = 0;

        String update = "update book "+
                        "set rating=rating+1 "+
                        "where book_name like '%"+keyword+"%' and rating<=4; ";
        String query = "select sum(rating) from book; ";
        
        try {
            Statement st = this.con.createStatement();
            st.executeUpdate(update);
            rs = st.executeQuery(query);
            
            rs.next();
            sum = rs.getDouble("sum(rating)");

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return sum;
    }
    
    @Override
    public int function10(){
        ResultSet rs;
        int count = 0;

        String update = "delete from publisher "+
                        "where publisher.publisher_id not in (select pid "+
                                                            "from (select distinct book.publisher_id as pid "+
								"from publisher inner join book ON book.publisher_id=publisher.publisher_id) as p);";
        String query = "select count(*) from publisher; ";
        
        try {
            Statement st = this.con.createStatement();
            st.executeUpdate(update);
            rs = st.executeQuery(query);
            
            rs.next();
            count = rs.getInt("count(*)");

            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return count;
    }
}
