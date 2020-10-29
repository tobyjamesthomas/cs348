static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,97,65,75,82,83,100,75,107,48,49,49,49,
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
    short aid, pubid;
    char title[26], type[12], year[5];
    char name[11];

/*
EXEC SQL END DECLARE SECTION;
*/

#line 13 "bibauthor.sqc"


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./bibauthor <author-id>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 21 "bibauthor.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 23 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 23 "bibauthor.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 23 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 23 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 23 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 23 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 23 "bibauthor.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 23 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 23 "bibauthor.sqc"
  sqlastop(0L);
}

#line 23 "bibauthor.sqc"


    aid = atoi(argv[1]);

    /* printf("%d", :aid); */

    
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
        FULL OUTER JOIN book ON book.pubid=pub.pubid
        FULL OUTER JOIN journal ON journal.pubid=pub.pubid
        FULL OUTER JOIN proceedings ON proceedings.pubid=pub.pubid
        WHERE book.pubid IN (
            SELECT publication
            FROM wrote
            WHERE :aid=author
        ) OR journal.pubid IN (
            SELECT appears_in
            FROM wrote, article
            WHERE :aid=author
            AND publication=article.pubid
        ) OR proceedings.pubid IN (
            SELECT appears_in
            FROM wrote, article
            WHERE :aid=author
            AND publication=article.pubid
        )
        ORDER BY year DESC, title;
*/

#line 60 "bibauthor.sqc"


    
/*
EXEC SQL OPEN publications;
*/

{
#line 62 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 62 "bibauthor.sqc"
  sqlaaloc(2,3,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&aid;
#line 62 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 62 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 62 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)&aid;
#line 62 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 62 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 500; sql_setdlist[2].sqllen = 2;
#line 62 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)&aid;
#line 62 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 62 "bibauthor.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 62 "bibauthor.sqc"
  sqlacall((unsigned short)26,1,2,0,0L);
#line 62 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 62 "bibauthor.sqc"
  sqlastop(0L);
}

#line 62 "bibauthor.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 63 "bibauthor.sqc"

    for (;;) {
        
/*
EXEC SQL FETCH publications INTO :pubid, :title, :type, :year;
*/

{
#line 65 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "bibauthor.sqc"
  sqlaaloc(3,4,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 65 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 65 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 65 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 65 "bibauthor.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 65 "bibauthor.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 65 "bibauthor.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 65 "bibauthor.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 12;
#line 65 "bibauthor.sqc"
      sql_setdlist[2].sqldata = (void*)type;
#line 65 "bibauthor.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 65 "bibauthor.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 5;
#line 65 "bibauthor.sqc"
      sql_setdlist[3].sqldata = (void*)year;
#line 65 "bibauthor.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 65 "bibauthor.sqc"
      sqlasetdata(3,0,4,sql_setdlist,0L,0L);
    }
#line 65 "bibauthor.sqc"
  sqlacall((unsigned short)25,1,0,3,0L);
#line 65 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 65 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 65 "bibauthor.sqc"
  sqlastop(0L);
}

#line 65 "bibauthor.sqc"

        printf("%d %s %s %s\n", pubid, title, type, year);
        if ( strcmp(type, "BOOK") == 0 ) {
            printf("Pubid: %d\n", pubid);
            printf("Type: %s\n", type);
            printf("Title: %s\n", title);

            
/*
EXEC SQL DECLARE authors CURSOR FOR
                SELECT name
                FROM author, wrote
                WHERE :pubid=publication
                AND aid=author
                ORDER BY name;
*/

#line 77 "bibauthor.sqc"


            
/*
EXEC SQL OPEN authors;
*/

{
#line 79 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 79 "bibauthor.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 79 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 79 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 79 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 79 "bibauthor.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 79 "bibauthor.sqc"
  sqlacall((unsigned short)26,2,2,0,0L);
#line 79 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 79 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 79 "bibauthor.sqc"
  sqlastop(0L);
}

#line 79 "bibauthor.sqc"

            
/*
EXEC SQL WHENEVER NOT FOUND GO TO book;
*/

#line 80 "bibauthor.sqc"

            for (;;) {
                
/*
EXEC SQL FETCH authors INTO :name;
*/

{
#line 82 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 82 "bibauthor.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 82 "bibauthor.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 82 "bibauthor.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 82 "bibauthor.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 82 "bibauthor.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 82 "bibauthor.sqc"
  sqlacall((unsigned short)25,2,0,3,0L);
#line 82 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 82 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 82 "bibauthor.sqc"
  sqlastop(0L);
}

#line 82 "bibauthor.sqc"

                printf("Author: %s\n", name);
            }
book:
            
/*
EXEC SQL CLOSE authors;
*/

{
#line 86 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 86 "bibauthor.sqc"
  sqlacall((unsigned short)20,2,0,0,0L);
#line 86 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 86 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 86 "bibauthor.sqc"
  sqlastop(0L);
}

#line 86 "bibauthor.sqc"

            printf("Publisher: \n");
            printf("Year: %s\n", year);
        } else if ( strcmp(type, "JOURNAL") == 0 || strcmp(type, "PROCEEDINGS") == 0 ) {
            printf("journal or proceedings\n");
        } else {
            // error
        }
    }

end:
    
/*
EXEC SQL CLOSE publications;
*/

{
#line 97 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 97 "bibauthor.sqc"
  sqlacall((unsigned short)20,1,0,0,0L);
#line 97 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 97 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 97 "bibauthor.sqc"
  sqlastop(0L);
}

#line 97 "bibauthor.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 99 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 99 "bibauthor.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
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
EXEC SQL CONNECT reset;
*/

{
#line 100 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 100 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 100 "bibauthor.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 100 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 100 "bibauthor.sqc"
  sqlastop(0L);
}

#line 100 "bibauthor.sqc"

    exit(0);

error:
    check_error("My error", &sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 105 "bibauthor.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 107 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 107 "bibauthor.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 107 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 107 "bibauthor.sqc"
  sqlastop(0L);
}

#line 107 "bibauthor.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 108 "bibauthor.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 108 "bibauthor.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 108 "bibauthor.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto book;
  }
#line 108 "bibauthor.sqc"
  sqlastop(0L);
}

#line 108 "bibauthor.sqc"

    exit(1);
}
