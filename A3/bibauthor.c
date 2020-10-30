static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,102,65,109,118,88,100,75,107,48,49,49,49,
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



/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 8 "bibauthor.sqc"

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

#line 28 "bibauthor.sqc"


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./bibauthor <author-id>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 36 "bibauthor.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 38 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 38 "bibauthor.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 38 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 38 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 38 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 38 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 38 "bibauthor.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 38 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 38 "bibauthor.sqc"
  sqlastop(0L);
}

#line 38 "bibauthor.sqc"


    aid = atoi(argv[1]);

    
/*
EXEC SQL SELECT COUNT(1) INTO :found
        FROM author
        WHERE :aid = aid;
*/

{
#line 44 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 44 "bibauthor.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 44 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 44 "bibauthor.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&found;
#line 44 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 44 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 44 "bibauthor.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 44 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 44 "bibauthor.sqc"
  sqlastop(0L);
}

#line 44 "bibauthor.sqc"


    if (found == 0) goto error;

    
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

#line 79 "bibauthor.sqc"


    
/*
EXEC SQL OPEN publications;
*/

{
#line 81 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 81 "bibauthor.sqc"
  sqlaaloc(2,3,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 81 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 81 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 81 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 81 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 81 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 81 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 81 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 81 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&aid;
#line 81 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 81 "bibauthor.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 81 "bibauthor.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 81 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 81 "bibauthor.sqc"
  sqlastop(0L);
}

#line 81 "bibauthor.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 82 "bibauthor.sqc"

    for ( ;; ) {
        
/*
EXEC SQL FETCH publications INTO :pubid, :title, :type, :year;
*/

{
#line 84 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 84 "bibauthor.sqc"
  sqlaaloc(3,4,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 84 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 84 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 84 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 84 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 84 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 12;
#line 84 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)type;
#line 84 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 84 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 5;
#line 84 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)year;
#line 84 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 84 "bibauthor.sqc"
      sqlasetdata(3,0,4,sql_setdlist,0L,0L);
    }
#line 84 "bibauthor.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 84 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 84 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 84 "bibauthor.sqc"
  sqlastop(0L);
}

#line 84 "bibauthor.sqc"


        if ( strcmp(type, "BOOK") == 0 ) {
            printf("Pubid: %d\n", pubid);
            printf("Type: %s\n", type);
            printf("Title: %s\n", title);

            
/*
EXEC SQL DECLARE b_authors CURSOR FOR
                SELECT name
                FROM author, wrote
                WHERE :pubid = publication
                AND aid = author
                ORDER BY name;
*/

#line 96 "bibauthor.sqc"


            
/*
EXEC SQL OPEN b_authors;
*/

{
#line 98 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 98 "bibauthor.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 98 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 98 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 98 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 98 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 98 "bibauthor.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 98 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 98 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 98 "bibauthor.sqc"
  sqlastop(0L);
}

#line 98 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO book;
*/

#line 99 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH b_authors INTO :name;
*/

{
#line 101 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 101 "bibauthor.sqc"
  sqlaaloc(3,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 101 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 101 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 101 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 101 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 101 "bibauthor.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 101 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 101 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 101 "bibauthor.sqc"
  sqlastop(0L);
}

#line 101 "bibauthor.sqc"

                printf("Author: %s\n", name);
            }

book:
            
/*
EXEC SQL CLOSE b_authors;
*/

{
#line 106 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 106 "bibauthor.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 106 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 106 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 106 "bibauthor.sqc"
  sqlastop(0L);
}

#line 106 "bibauthor.sqc"


            
/*
EXEC SQL SELECT publisher INTO :publisher
                FROM book
                WHERE :pubid = pubid;
*/

{
#line 110 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 110 "bibauthor.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 110 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 110 "bibauthor.sqc"
  sqlaaloc(3,1,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)publisher;
#line 110 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 110 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 110 "bibauthor.sqc"
  sqlacall((unsigned short)24,4,2,3,0L);
#line 110 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 110 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 110 "bibauthor.sqc"
  sqlastop(0L);
}

#line 110 "bibauthor.sqc"


            printf("Publisher: %s\n", publisher);
            printf("Year: %s\n", year);
        } else if ( strcmp(type, "JOURNAL") == 0 || strcmp(type, "PROCEEDINGS") == 0 ) {
            
/*
EXEC SQL DECLARE articles CURSOR FOR
                SELECT publication, title, appears_in, startpage, endpage
                FROM wrote, publication AS p, article AS a
                WHERE :aid = author
                AND publication = p.pubid AND publication = a.pubid
                AND :pubid = appears_in
                ORDER BY title;
*/

#line 121 "bibauthor.sqc"


            
/*
EXEC SQL OPEN articles;
*/

{
#line 123 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 123 "bibauthor.sqc"
  sqlaaloc(2,2,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 123 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 123 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 123 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 123 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 123 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&pubid;
#line 123 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 123 "bibauthor.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 123 "bibauthor.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 123 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 123 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 123 "bibauthor.sqc"
  sqlastop(0L);
}

#line 123 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO j_or_p;
*/

#line 124 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH articles INTO :a_pubid, :a_title, :appears_in, :startpage, :endpage;
*/

{
#line 126 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 126 "bibauthor.sqc"
  sqlaaloc(3,5,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&a_pubid;
#line 126 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 126 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)a_title;
#line 126 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 126 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&appears_in;
#line 126 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 126 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 126 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 126 "bibauthor.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 126 "bibauthor.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 126 "bibauthor.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 126 "bibauthor.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
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
    goto j_or_p;
  }
#line 126 "bibauthor.sqc"
  sqlastop(0L);
}

#line 126 "bibauthor.sqc"

                printf("Pubid: %d\n", a_pubid);
                printf("Type: ARTICLE\n");
                printf("Title: %s\n", a_title);

                
/*
EXEC SQL DECLARE a_authors CURSOR FOR
                    SELECT name
                    FROM author, wrote
                    WHERE :a_pubid = publication
                    AND aid = author
                    ORDER BY name;
*/

#line 136 "bibauthor.sqc"


                
/*
EXEC SQL OPEN a_authors;
*/

{
#line 138 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 138 "bibauthor.sqc"
  sqlaaloc(2,1,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 138 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 138 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&a_pubid;
#line 138 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 138 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 138 "bibauthor.sqc"
  sqlacall((unsigned short)26,6,2,0,0L);
#line 138 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 138 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto j_or_p;
  }
#line 138 "bibauthor.sqc"
  sqlastop(0L);
}

#line 138 "bibauthor.sqc"

                
/*
EXEC SQL WHENEVER NOT FOUND GO TO article;
*/

#line 139 "bibauthor.sqc"

                for ( ;; ) {
                    
/*
EXEC SQL FETCH a_authors INTO :name;
*/

{
#line 141 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 141 "bibauthor.sqc"
  sqlaaloc(3,1,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 141 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 141 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 141 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 141 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 141 "bibauthor.sqc"
  sqlacall((unsigned short)25,6,0,3,0L);
#line 141 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 141 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 141 "bibauthor.sqc"
  sqlastop(0L);
}

#line 141 "bibauthor.sqc"

                    printf("Author: %s\n", name);
                }

article:
                
/*
EXEC SQL CLOSE a_authors;
*/

{
#line 146 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 146 "bibauthor.sqc"
  sqlacall((unsigned short)20,6,0,0,0L);
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
    goto article;
  }
#line 146 "bibauthor.sqc"
  sqlastop(0L);
}

#line 146 "bibauthor.sqc"

                printf("In: %d\n", appears_in);
                printf("Pages: %d--%d\n", startpage, endpage);
                printf("\n");
            }

j_or_p:
            
/*
EXEC SQL CLOSE articles;
*/

{
#line 153 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 153 "bibauthor.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 153 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 153 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 153 "bibauthor.sqc"
  sqlastop(0L);
}

#line 153 "bibauthor.sqc"


            printf("Pubid: %d\n", pubid);
            printf("Type: %s\n", type);
            printf("Title: %s\n", title);

            if ( strcmp(type, "JOURNAL") == 0 ) {
                
/*
EXEC SQL SELECT volume, number INTO :volume, :number
                    FROM journal
                    WHERE :pubid = pubid;
*/

{
#line 162 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 162 "bibauthor.sqc"
  sqlaaloc(2,1,14,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 162 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 162 "bibauthor.sqc"
  sqlaaloc(3,2,15,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&volume;
#line 162 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 162 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 162 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&number;
#line 162 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 162 "bibauthor.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 162 "bibauthor.sqc"
  sqlacall((unsigned short)24,7,2,3,0L);
#line 162 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 162 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 162 "bibauthor.sqc"
  sqlastop(0L);
}

#line 162 "bibauthor.sqc"


                printf("Volume: %d\n", volume);
                printf("Number: %d\n", number);
            }

            printf("Year: %s\n", year);
        }

        printf("\n");
    }

end:
    
/*
EXEC SQL CLOSE publications;
*/

{
#line 175 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 175 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 175 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 175 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 175 "bibauthor.sqc"
  sqlastop(0L);
}

#line 175 "bibauthor.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 177 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 177 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 177 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 177 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 177 "bibauthor.sqc"
  sqlastop(0L);
}

#line 177 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 178 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 178 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 178 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 178 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 178 "bibauthor.sqc"
  sqlastop(0L);
}

#line 178 "bibauthor.sqc"

    exit(0);

error:
    printf("ERROR\n");
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 183 "bibauthor.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 185 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 185 "bibauthor.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 185 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 185 "bibauthor.sqc"
  sqlastop(0L);
}

#line 185 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 186 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 186 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 186 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 186 "bibauthor.sqc"
  sqlastop(0L);
}

#line 186 "bibauthor.sqc"

    exit(1);
}
