static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,68,66,67,67,79,101,75,107,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,84,74,84,72,79,77,
 65,83,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,66,73,66,67,79,78,84,69,0,0,0,0,0,0,0,0,
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


#line 1 "bibcontent.sqc"
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


#line 6 "bibcontent.sqc"



// Declare variables for SQL queries

/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 10 "bibcontent.sqc"

    char db[6] = "cs348";

    // general
    sqlint32 pubid, found;
    char title[26], type[12], year[5];

    // journal
    sqlint32 volume, number;

    // article
    sqlint32 appears_in, startpage, endpage;

    // author
    char name[11];

/*
EXEC SQL END DECLARE SECTION;
*/

#line 25 "bibcontent.sqc"



int main(int argc, char * argv[]) {
    // Print error if wrong number of arguments
    if (argc != 2) {
        printf("Usage: ./bibcontent <pubid>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 35 "bibcontent.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 37 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 37 "bibcontent.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 37 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 37 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 37 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 37 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 37 "bibcontent.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 37 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 37 "bibcontent.sqc"
  sqlastop(0L);
}

#line 37 "bibcontent.sqc"


    // Get pubid from command line
    pubid = atoi(argv[1]);

    // Check if pubid belongs to a journal or proceedings
    
/*
EXEC SQL SELECT COUNT(1) INTO :found
        FROM journal_or_proceedings
        WHERE :pubid = pubid;
*/

{
#line 45 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 45 "bibcontent.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 45 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 45 "bibcontent.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&found;
#line 45 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 45 "bibcontent.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 45 "bibcontent.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 45 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 45 "bibcontent.sqc"
  sqlastop(0L);
}

#line 45 "bibcontent.sqc"


    // Go to error if journal or proceedings not found
    if (found == 0) goto error;

    // Get journal or proceedings
    
/*
EXEC SQL SELECT title,
        CASE
            WHEN j.pubid IS NOT NULL THEN 'JOURNAL'
            WHEN pro.pubid IS NOT NULL THEN 'PROCEEDINGS'
        END AS type,
        CASE
            WHEN j.year IS NOT NULL THEN j.year
            WHEN pro.year IS NOT NULL THEN pro.year
        END AS year
        INTO :title, :type, :year
        FROM publication AS pub
        FULL OUTER JOIN journal AS j ON j.pubid = pub.pubid
        FULL OUTER JOIN proceedings AS pro ON pro.pubid = pub.pubid
        WHERE :pubid = pub.pubid;
*/

{
#line 64 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 64 "bibcontent.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 64 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 64 "bibcontent.sqc"
  sqlaaloc(3,3,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 26;
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 64 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 64 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 12;
#line 64 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)type;
#line 64 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 64 "bibcontent.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 5;
#line 64 "bibcontent.sqc"
      sql_setdlist[2].sqldata = (void*)year;
#line 64 "bibcontent.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 64 "bibcontent.sqc"
      sqlasetdata(3,0,3,sql_setdlist,0L,0L);
    }
#line 64 "bibcontent.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 64 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 64 "bibcontent.sqc"
  sqlastop(0L);
}

#line 64 "bibcontent.sqc"


    // Print journal or proceedings
    printf("Pubid: %d\n", pubid);
    printf("Type: %s\n", type);
    printf("Title: %s\n", title);

    // If journal, print journal's volume and number
    if (strcmp(type, "JOURNAL") == 0) {
        
/*
EXEC SQL SELECT volume, number INTO :volume, :number
            FROM journal
            WHERE :pubid = pubid;
*/

{
#line 75 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 75 "bibcontent.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 75 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 75 "bibcontent.sqc"
  sqlaaloc(3,2,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&volume;
#line 75 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 75 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 75 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)&number;
#line 75 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 75 "bibcontent.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 75 "bibcontent.sqc"
  sqlacall((unsigned short)24,3,2,3,0L);
#line 75 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 75 "bibcontent.sqc"
  sqlastop(0L);
}

#line 75 "bibcontent.sqc"


        printf("Volume: %d\n", volume);
        printf("Number: %d\n", number);
    }

    printf("Year: %s\n", year);

    // Print table of contents
    printf("\n");
    printf("Table of Contents:\n");
    printf("\n");

    // Get articles that appear in journal or proceedings
    // Sort by start page
    
/*
EXEC SQL DECLARE articles CURSOR FOR
        SELECT a.pubid, title, appears_in, startpage, endpage
        FROM article AS a, publication AS p
        WHERE :pubid = appears_in
        AND p.pubid = a.pubid
        ORDER BY startpage;
*/

#line 95 "bibcontent.sqc"


    // Print articles
    
/*
EXEC SQL OPEN articles;
*/

{
#line 98 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 98 "bibcontent.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 98 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 98 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 98 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 98 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 98 "bibcontent.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 98 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 98 "bibcontent.sqc"
  sqlastop(0L);
}

#line 98 "bibcontent.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 99 "bibcontent.sqc"

    for ( ;; ) {
        
/*
EXEC SQL FETCH articles INTO :pubid, :title, :appears_in, :startpage, :endpage;
*/

{
#line 101 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 101 "bibcontent.sqc"
  sqlaaloc(3,5,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 101 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 101 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 101 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 101 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 101 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 101 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 101 "bibcontent.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 101 "bibcontent.sqc"
      sql_setdlist[2].sqldata = (void*)&appears_in;
#line 101 "bibcontent.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 101 "bibcontent.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 101 "bibcontent.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 101 "bibcontent.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 101 "bibcontent.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 101 "bibcontent.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 101 "bibcontent.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 101 "bibcontent.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 101 "bibcontent.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 101 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 101 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 101 "bibcontent.sqc"
  sqlastop(0L);
}

#line 101 "bibcontent.sqc"

        printf("Pubid: %d\n", pubid);
        printf("Type: ARTICLE\n");
        printf("Title: %s\n", title);

        // Get list of article's authors
        // Sort by name
        
/*
EXEC SQL DECLARE authors CURSOR FOR
            SELECT name
            FROM author, wrote
            WHERE :pubid = publication
            AND aid = author
            ORDER BY name;
*/

#line 113 "bibcontent.sqc"


        // Print authors
        
/*
EXEC SQL OPEN authors;
*/

{
#line 116 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 116 "bibcontent.sqc"
  sqlaaloc(2,1,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 116 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 116 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 116 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 116 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 116 "bibcontent.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 116 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 116 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 116 "bibcontent.sqc"
  sqlastop(0L);
}

#line 116 "bibcontent.sqc"

        
/*
EXEC SQL WHENEVER NOT FOUND GO TO article;
*/

#line 117 "bibcontent.sqc"

        for ( ;; ) {
            
/*
EXEC SQL FETCH authors INTO :name;
*/

{
#line 119 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 119 "bibcontent.sqc"
  sqlaaloc(3,1,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 119 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 119 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 119 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 119 "bibcontent.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 119 "bibcontent.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
#line 119 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 119 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 119 "bibcontent.sqc"
  sqlastop(0L);
}

#line 119 "bibcontent.sqc"

            printf("Author: %s\n", name);
        }

article:
        
/*
EXEC SQL CLOSE authors;
*/

{
#line 124 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 124 "bibcontent.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 124 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 124 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 124 "bibcontent.sqc"
  sqlastop(0L);
}

#line 124 "bibcontent.sqc"


        // Print remaining article info
        printf("In: %d\n", appears_in);
        printf("Pages: %d--%d\n", startpage, endpage);
        printf("\n");
    }

end:
    
/*
EXEC SQL CLOSE articles;
*/

{
#line 133 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 133 "bibcontent.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 133 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 133 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 133 "bibcontent.sqc"
  sqlastop(0L);
}

#line 133 "bibcontent.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 135 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 135 "bibcontent.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 135 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 135 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 135 "bibcontent.sqc"
  sqlastop(0L);
}

#line 135 "bibcontent.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 136 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 136 "bibcontent.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 136 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 136 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 136 "bibcontent.sqc"
  sqlastop(0L);
}

#line 136 "bibcontent.sqc"

    exit(0);

error:
    printf("Error\n");
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 141 "bibcontent.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 143 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 143 "bibcontent.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 143 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 143 "bibcontent.sqc"
  sqlastop(0L);
}

#line 143 "bibcontent.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 144 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 144 "bibcontent.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 144 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 144 "bibcontent.sqc"
  sqlastop(0L);
}

#line 144 "bibcontent.sqc"

    exit(1);
}
