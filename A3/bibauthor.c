static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,103,66,66,67,79,101,75,107,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,84,74,84,72,79,77,
 65,83,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,65,85,84,72,79,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "bibauthor.sqc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 6 "bibauthor.sqc"



// Declare variables for SQL queries

/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 10 "bibauthor.sqc"

    char db[6] = "cs348";

    // general
    sqlint32 aid, found;
    sqlint32 pubid;
    char title[26], type[12], year[5];

    // book
    char publisher[11];

    // journal
    sqlint32 volume, number;

    // article
    char a_title[26];
    sqlint32 a_pubid, appears_in, startpage, endpage;

    // author
    char name[11];

/*
EXEC SQL END DECLARE SECTION;
*/

#line 30 "bibauthor.sqc"



int main(int argc, char * argv[]) {
    // Print error if wrong number of arguments
    if (argc != 2) {
        printf("Usage: ./bibauthor <author-id>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 40 "bibauthor.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 42 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 42 "bibauthor.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 42 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 42 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 42 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 42 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 42 "bibauthor.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 42 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 42 "bibauthor.sqc"
  sqlastop(0L);
}

#line 42 "bibauthor.sqc"


    // Get aid from command line
    aid = atoi(argv[1]);

    // Check if author exists
    
/*
EXEC SQL SELECT COUNT(1) INTO :found
        FROM author
        WHERE :aid = aid;
*/

{
#line 50 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 50 "bibauthor.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 50 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 50 "bibauthor.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&found;
#line 50 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 50 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 50 "bibauthor.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 50 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 50 "bibauthor.sqc"
  sqlastop(0L);
}

#line 50 "bibauthor.sqc"


    // Go to error if author not found
    if (found == 0) goto error;

    // Get list of books, journals and publications the author appears in
    // Sort by year, then title
    
/*
EXEC SQL DECLARE publications CURSOR FOR
        SELECT pub.pubid, title,
        CASE
            WHEN book.year IS NOT NULL THEN 'BOOK'
            WHEN journal.year IS NOT NULL THEN 'JOURNAL'
            WHEN proceedings.year IS NOT NULL THEN 'PROCEEDINGS'
        END AS type,
        CASE
            WHEN book.year IS NOT NULL THEN book.year
            WHEN journal.year IS NOT NULL THEN journal.year
            WHEN proceedings.year IS NOT NULL THEN proceedings.year
        END AS year
        FROM publication AS pub
        FULL OUTER JOIN book ON book.pubid = pub.pubid
        FULL OUTER JOIN journal ON journal.pubid = pub.pubid
        FULL OUTER JOIN proceedings ON proceedings.pubid = pub.pubid
        WHERE book.pubid IN (
            SELECT publication
            FROM wrote
            WHERE :aid = author
        ) OR journal.pubid IN (
            SELECT appears_in
            FROM wrote, article
            WHERE :aid = author
            AND publication = article.pubid
        ) OR proceedings.pubid IN (
            SELECT appears_in
            FROM wrote, article
            WHERE :aid = author
            AND publication = article.pubid
        )
        ORDER BY year DESC, title;
*/

#line 88 "bibauthor.sqc"


    // Print publications
    
/*
EXEC SQL OPEN publications;
*/

{
#line 91 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 91 "bibauthor.sqc"
  sqlaaloc(2,3,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 91 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 91 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 91 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 91 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 91 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&aid;
#line 91 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 91 "bibauthor.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 91 "bibauthor.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 91 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 91 "bibauthor.sqc"
  sqlastop(0L);
}

#line 91 "bibauthor.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 92 "bibauthor.sqc"

    for ( ;; ) {
        
/*
EXEC SQL FETCH publications INTO :pubid, :title, :type, :year;
*/

{
#line 94 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 94 "bibauthor.sqc"
  sqlaaloc(3,4,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 94 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 94 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 94 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 94 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 12;
#line 94 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)type;
#line 94 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 94 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 5;
#line 94 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)year;
#line 94 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 94 "bibauthor.sqc"
      sqlasetdata(3,0,4,sql_setdlist,0L,0L);
    }
#line 94 "bibauthor.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 94 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 94 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 94 "bibauthor.sqc"
  sqlastop(0L);
}

#line 94 "bibauthor.sqc"


        if ( strcmp(type, "BOOK") == 0 ) { // Book

            // Print book info
            printf("Pubid: %d\n", pubid);
            printf("Type: %s\n", type);
            printf("Title: %s\n", title);

            // Get list of book's authors
            // Sort by name
            
/*
EXEC SQL DECLARE b_authors CURSOR FOR
                SELECT name
                FROM author, wrote
                WHERE :pubid = publication
                AND aid = author
                ORDER BY name;
*/

#line 110 "bibauthor.sqc"


            // Print authors
            
/*
EXEC SQL OPEN b_authors;
*/

{
#line 113 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 113 "bibauthor.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 113 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 113 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 113 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 113 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 113 "bibauthor.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 113 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 113 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 113 "bibauthor.sqc"
  sqlastop(0L);
}

#line 113 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO book;
*/

#line 114 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH b_authors INTO :name;
*/

{
#line 116 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 116 "bibauthor.sqc"
  sqlaaloc(3,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 116 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 116 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 116 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 116 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 116 "bibauthor.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 116 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 116 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 116 "bibauthor.sqc"
  sqlastop(0L);
}

#line 116 "bibauthor.sqc"

                printf("Author: %s\n", name);
            }

book:
            
/*
EXEC SQL CLOSE b_authors;
*/

{
#line 121 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 121 "bibauthor.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 121 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 121 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 121 "bibauthor.sqc"
  sqlastop(0L);
}

#line 121 "bibauthor.sqc"


            // Get book's publisher
            
/*
EXEC SQL SELECT publisher INTO :publisher
                FROM book
                WHERE :pubid = pubid;
*/

{
#line 126 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 126 "bibauthor.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 126 "bibauthor.sqc"
  sqlaaloc(3,1,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)publisher;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 126 "bibauthor.sqc"
  sqlacall((unsigned short)24,4,2,3,0L);
#line 126 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 126 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 126 "bibauthor.sqc"
  sqlastop(0L);
}

#line 126 "bibauthor.sqc"


            printf("Publisher: %s\n", publisher);
            printf("Year: %s\n", year);
        } else if ( strcmp(type, "JOURNAL") == 0 || strcmp(type, "PROCEEDINGS") == 0 ) { // Journal or Proceedings

            // Get the author's articles the appear in the journal or proceedings
            // Sort by title
            
/*
EXEC SQL DECLARE articles CURSOR FOR
                SELECT publication, title, appears_in, startpage, endpage
                FROM wrote, publication AS p, article AS a
                WHERE :aid = author
                AND publication = p.pubid AND publication = a.pubid
                AND :pubid = appears_in
                ORDER BY title;
*/

#line 140 "bibauthor.sqc"


            // Print the articles before the journal or proceedings
            
/*
EXEC SQL OPEN articles;
*/

{
#line 143 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 143 "bibauthor.sqc"
  sqlaaloc(2,2,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 143 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 143 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 143 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 143 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 143 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&pubid;
#line 143 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 143 "bibauthor.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 143 "bibauthor.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 143 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 143 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 143 "bibauthor.sqc"
  sqlastop(0L);
}

#line 143 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO j_or_p;
*/

#line 144 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH articles INTO :a_pubid, :a_title, :appears_in, :startpage, :endpage;
*/

{
#line 146 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 146 "bibauthor.sqc"
  sqlaaloc(3,5,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&a_pubid;
#line 146 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 146 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)a_title;
#line 146 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 146 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&appears_in;
#line 146 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 146 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 146 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 146 "bibauthor.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 146 "bibauthor.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 146 "bibauthor.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 146 "bibauthor.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
#line 146 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 146 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto j_or_p;
  }
#line 146 "bibauthor.sqc"
  sqlastop(0L);
}

#line 146 "bibauthor.sqc"

                printf("Pubid: %d\n", a_pubid);
                printf("Type: ARTICLE\n");
                printf("Title: %s\n", a_title);

                // Get list of article's authors
                // Sort by name
                
/*
EXEC SQL DECLARE a_authors CURSOR FOR
                    SELECT name
                    FROM author, wrote
                    WHERE :a_pubid = publication
                    AND aid = author
                    ORDER BY name;
*/

#line 158 "bibauthor.sqc"


                // Print authors
                
/*
EXEC SQL OPEN a_authors;
*/

{
#line 161 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 161 "bibauthor.sqc"
  sqlaaloc(2,1,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 161 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 161 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&a_pubid;
#line 161 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 161 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 161 "bibauthor.sqc"
  sqlacall((unsigned short)26,6,2,0,0L);
#line 161 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 161 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto j_or_p;
  }
#line 161 "bibauthor.sqc"
  sqlastop(0L);
}

#line 161 "bibauthor.sqc"

                
/*
EXEC SQL WHENEVER NOT FOUND GO TO article;
*/

#line 162 "bibauthor.sqc"

                for ( ;; ) {
                    
/*
EXEC SQL FETCH a_authors INTO :name;
*/

{
#line 164 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 164 "bibauthor.sqc"
  sqlaaloc(3,1,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 164 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 164 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 164 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 164 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 164 "bibauthor.sqc"
  sqlacall((unsigned short)25,6,0,3,0L);
#line 164 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 164 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 164 "bibauthor.sqc"
  sqlastop(0L);
}

#line 164 "bibauthor.sqc"

                    printf("Author: %s\n", name);
                }

article:
                
/*
EXEC SQL CLOSE a_authors;
*/

{
#line 169 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 169 "bibauthor.sqc"
  sqlacall((unsigned short)20,6,0,0,0L);
#line 169 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 169 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 169 "bibauthor.sqc"
  sqlastop(0L);
}

#line 169 "bibauthor.sqc"

                printf("In: %d\n", appears_in);
                printf("Pages: %d--%d\n", startpage, endpage);
                printf("\n"); // Blank line
            }

j_or_p:
            
/*
EXEC SQL CLOSE articles;
*/

{
#line 176 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 176 "bibauthor.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 176 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 176 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 176 "bibauthor.sqc"
  sqlastop(0L);
}

#line 176 "bibauthor.sqc"


            // Print the journal or proceeding
            printf("Pubid: %d\n", pubid);
            printf("Type: %s\n", type);
            printf("Title: %s\n", title);

            // If journal, then print journal's volume and number
            if ( strcmp(type, "JOURNAL") == 0 ) {
                
/*
EXEC SQL SELECT volume, number INTO :volume, :number
                    FROM journal
                    WHERE :pubid = pubid;
*/

{
#line 187 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 187 "bibauthor.sqc"
  sqlaaloc(2,1,14,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 187 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 187 "bibauthor.sqc"
  sqlaaloc(3,2,15,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&volume;
#line 187 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 187 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 187 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&number;
#line 187 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 187 "bibauthor.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 187 "bibauthor.sqc"
  sqlacall((unsigned short)24,7,2,3,0L);
#line 187 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 187 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 187 "bibauthor.sqc"
  sqlastop(0L);
}

#line 187 "bibauthor.sqc"


                printf("Volume: %d\n", volume);
                printf("Number: %d\n", number);
            }

            printf("Year: %s\n", year);
        }

        printf("\n"); // Blank line
    }

end:
    
/*
EXEC SQL CLOSE publications;
*/

{
#line 200 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 200 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 200 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 200 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 200 "bibauthor.sqc"
  sqlastop(0L);
}

#line 200 "bibauthor.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 202 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 202 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 202 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 202 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 202 "bibauthor.sqc"
  sqlastop(0L);
}

#line 202 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 203 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 203 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 203 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 203 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 203 "bibauthor.sqc"
  sqlastop(0L);
}

#line 203 "bibauthor.sqc"

    exit(0);

error:
    printf("Error\n");
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 208 "bibauthor.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 210 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 210 "bibauthor.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 210 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 210 "bibauthor.sqc"
  sqlastop(0L);
}

#line 210 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 211 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 211 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 211 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 211 "bibauthor.sqc"
  sqlastop(0L);
}

#line 211 "bibauthor.sqc"

    exit(1);
}
