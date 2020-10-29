static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,56,65,53,109,84,100,75,107,48,49,49,49,
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
    sqlint32 aid, pubid;
    char title[26], type[12], year[5];

    // author
    char name[11];

    // book
    char publisher[11];

    // article
    char atitle[26];
    sqlint32 artid, appears_in, startpage, endpage;

    // journal
    sqlint32 volume, number;

/*
EXEC SQL END DECLARE SECTION;
*/

#line 27 "bibauthor.sqc"


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./bibauthor <author-id>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 35 "bibauthor.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 37 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 37 "bibauthor.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 37 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 37 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 37 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 37 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 37 "bibauthor.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 37 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 37 "bibauthor.sqc"
  sqlastop(0L);
}

#line 37 "bibauthor.sqc"


    aid = atoi(argv[1]);

    
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

#line 72 "bibauthor.sqc"


    
/*
EXEC SQL OPEN publications;
*/

{
#line 74 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 74 "bibauthor.sqc"
  sqlaaloc(2,3,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 74 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 74 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 74 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 74 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 74 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 74 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 74 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 74 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&aid;
#line 74 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 74 "bibauthor.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 74 "bibauthor.sqc"
  sqlacall((unsigned short)26,1,2,0,0L);
#line 74 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 74 "bibauthor.sqc"
  sqlastop(0L);
}

#line 74 "bibauthor.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 75 "bibauthor.sqc"

    for ( ;; ) {
        
/*
EXEC SQL FETCH publications INTO :pubid, :title, :type, :year;
*/

{
#line 77 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 77 "bibauthor.sqc"
  sqlaaloc(3,4,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 77 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 77 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 77 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 77 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 77 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 77 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 77 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 12;
#line 77 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)type;
#line 77 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 77 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 5;
#line 77 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)year;
#line 77 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 77 "bibauthor.sqc"
      sqlasetdata(3,0,4,sql_setdlist,0L,0L);
    }
#line 77 "bibauthor.sqc"
  sqlacall((unsigned short)25,1,0,3,0L);
#line 77 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 77 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 77 "bibauthor.sqc"
  sqlastop(0L);
}

#line 77 "bibauthor.sqc"


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

#line 89 "bibauthor.sqc"


            
/*
EXEC SQL OPEN b_authors;
*/

{
#line 91 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 91 "bibauthor.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 91 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 91 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
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
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 91 "bibauthor.sqc"
  sqlastop(0L);
}

#line 91 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO book;
*/

#line 92 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH b_authors INTO :name;
*/

{
#line 94 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 94 "bibauthor.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 94 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 94 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
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
    goto book;
  }
#line 94 "bibauthor.sqc"
  sqlastop(0L);
}

#line 94 "bibauthor.sqc"

                printf("Author: %s\n", name);
            }

book:
            
/*
EXEC SQL CLOSE b_authors;
*/

{
#line 99 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 99 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 99 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 99 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 99 "bibauthor.sqc"
  sqlastop(0L);
}

#line 99 "bibauthor.sqc"

            
/*
EXEC SQL SELECT publisher INTO :publisher
                FROM book
                WHERE :pubid = pubid;
*/

{
#line 102 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 102 "bibauthor.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 102 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 102 "bibauthor.sqc"
  sqlaaloc(3,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)publisher;
#line 102 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 102 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 102 "bibauthor.sqc"
  sqlacall((unsigned short)24,3,2,3,0L);
#line 102 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 102 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 102 "bibauthor.sqc"
  sqlastop(0L);
}

#line 102 "bibauthor.sqc"


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

#line 113 "bibauthor.sqc"


            
/*
EXEC SQL OPEN articles;
*/

{
#line 115 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 115 "bibauthor.sqc"
  sqlaaloc(2,2,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 115 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 115 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 115 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 115 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 115 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&pubid;
#line 115 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 115 "bibauthor.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 115 "bibauthor.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 115 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 115 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 115 "bibauthor.sqc"
  sqlastop(0L);
}

#line 115 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO jorp;
*/

#line 116 "bibauthor.sqc"

            for ( ;; ) {
                
/*
EXEC SQL FETCH articles INTO :artid, :atitle, :appears_in, :startpage, :endpage;
*/

{
#line 118 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 118 "bibauthor.sqc"
  sqlaaloc(3,5,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 118 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 118 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&artid;
#line 118 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 118 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 118 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)atitle;
#line 118 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 118 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 118 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&appears_in;
#line 118 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 118 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 118 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 118 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 118 "bibauthor.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 118 "bibauthor.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 118 "bibauthor.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 118 "bibauthor.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 118 "bibauthor.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 118 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 118 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto jorp;
  }
#line 118 "bibauthor.sqc"
  sqlastop(0L);
}

#line 118 "bibauthor.sqc"

                printf("Pubid: %d\n", artid);
                printf("Type: ARTICLE\n");
                printf("Title: %s\n", atitle);

                
/*
EXEC SQL DECLARE a_authors CURSOR FOR
                    SELECT name
                    FROM author, wrote
                    WHERE :artid = publication
                    AND aid = author
                    ORDER BY name;
*/

#line 128 "bibauthor.sqc"


                
/*
EXEC SQL OPEN a_authors;
*/

{
#line 130 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 130 "bibauthor.sqc"
  sqlaaloc(2,1,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&artid;
#line 130 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 130 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 130 "bibauthor.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 130 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 130 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto jorp;
  }
#line 130 "bibauthor.sqc"
  sqlastop(0L);
}

#line 130 "bibauthor.sqc"

                
/*
EXEC SQL WHENEVER NOT FOUND GO TO article;
*/

#line 131 "bibauthor.sqc"

                for ( ;; ) {
                    
/*
EXEC SQL FETCH a_authors INTO :name;
*/

{
#line 133 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 133 "bibauthor.sqc"
  sqlaaloc(3,1,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 133 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 133 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 133 "bibauthor.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
#line 133 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 133 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 133 "bibauthor.sqc"
  sqlastop(0L);
}

#line 133 "bibauthor.sqc"

                    printf("Author: %s\n", name);
                }

article:
                
/*
EXEC SQL CLOSE a_authors;
*/

{
#line 138 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 138 "bibauthor.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
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
    goto article;
  }
#line 138 "bibauthor.sqc"
  sqlastop(0L);
}

#line 138 "bibauthor.sqc"

                printf("In: %d\n", appears_in);
                printf("Pages: %d--%d\n", startpage, endpage);
                printf("\n");
            }

jorp:
            
/*
EXEC SQL CLOSE articles;
*/

{
#line 145 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 145 "bibauthor.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 145 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 145 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 145 "bibauthor.sqc"
  sqlastop(0L);
}

#line 145 "bibauthor.sqc"

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
#line 153 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 153 "bibauthor.sqc"
  sqlaaloc(2,1,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 153 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 153 "bibauthor.sqc"
  sqlaaloc(3,2,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&volume;
#line 153 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 153 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 153 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&number;
#line 153 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 153 "bibauthor.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 153 "bibauthor.sqc"
  sqlacall((unsigned short)24,6,2,3,0L);
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


                printf("Volume: %d\n", volume);
                printf("Number: %d\n", number);
            }

            printf("Year: %s\n", year);
        } else {
            // error
        }

        printf("\n");
    }

end:
    
/*
EXEC SQL CLOSE publications;
*/

{
#line 168 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 168 "bibauthor.sqc"
  sqlacall((unsigned short)20,1,0,0,0L);
#line 168 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 168 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 168 "bibauthor.sqc"
  sqlastop(0L);
}

#line 168 "bibauthor.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 170 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 170 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 170 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 170 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 170 "bibauthor.sqc"
  sqlastop(0L);
}

#line 170 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 171 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 171 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 171 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 171 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 171 "bibauthor.sqc"
  sqlastop(0L);
}

#line 171 "bibauthor.sqc"

    exit(0);

error:
    check_error("My error", &sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 176 "bibauthor.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 178 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 178 "bibauthor.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
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

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 179 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 179 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 179 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 179 "bibauthor.sqc"
  sqlastop(0L);
}

#line 179 "bibauthor.sqc"

    exit(1);
}
