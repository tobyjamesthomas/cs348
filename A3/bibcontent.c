static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,84,66,109,118,88,100,75,107,48,49,49,49,
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



/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 8 "bibcontent.sqc"

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

#line 23 "bibcontent.sqc"


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./bibcontent <pubid>\n");
        exit(1);
    }

    
/*
EXEC SQL WHENEVER SQLERROR GO TO error;
*/

#line 31 "bibcontent.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 33 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 33 "bibcontent.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 33 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 33 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 33 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 33 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 33 "bibcontent.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 33 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 33 "bibcontent.sqc"
  sqlastop(0L);
}

#line 33 "bibcontent.sqc"


    pubid = atoi(argv[1]);

    
/*
EXEC SQL SELECT COUNT(1) INTO :found
        FROM journal_or_proceedings
        WHERE :pubid = pubid;
*/

{
#line 39 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 39 "bibcontent.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 39 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 39 "bibcontent.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&found;
#line 39 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 39 "bibcontent.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 39 "bibcontent.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 39 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 39 "bibcontent.sqc"
  sqlastop(0L);
}

#line 39 "bibcontent.sqc"


    if (found == 0) goto error;

    
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
#line 56 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 56 "bibcontent.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 56 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 56 "bibcontent.sqc"
  sqlaaloc(3,3,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 26;
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)title;
#line 56 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 56 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 12;
#line 56 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)type;
#line 56 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 56 "bibcontent.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 5;
#line 56 "bibcontent.sqc"
      sql_setdlist[2].sqldata = (void*)year;
#line 56 "bibcontent.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 56 "bibcontent.sqc"
      sqlasetdata(3,0,3,sql_setdlist,0L,0L);
    }
#line 56 "bibcontent.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 56 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 56 "bibcontent.sqc"
  sqlastop(0L);
}

#line 56 "bibcontent.sqc"


    printf("Pubid: %d\n", pubid);
    printf("Type: %s\n", type);
    printf("Title: %s\n", title);

    if (strcmp(type, "JOURNAL") == 0) {
        
/*
EXEC SQL SELECT volume, number INTO :volume, :number
            FROM journal
            WHERE :pubid = pubid;
*/

{
#line 65 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "bibcontent.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 65 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 65 "bibcontent.sqc"
  sqlaaloc(3,2,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&volume;
#line 65 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 65 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 496; sql_setdlist[1].sqllen = 4;
#line 65 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)&number;
#line 65 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 65 "bibcontent.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 65 "bibcontent.sqc"
  sqlacall((unsigned short)24,3,2,3,0L);
#line 65 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 65 "bibcontent.sqc"
  sqlastop(0L);
}

#line 65 "bibcontent.sqc"


        printf("Volume: %d\n", volume);
        printf("Number: %d\n", number);
    }

    printf("Year: %s\n", year);

    printf("\n");
    printf("Table of Contents:\n");
    printf("\n");

    
/*
EXEC SQL DECLARE articles CURSOR FOR
        SELECT a.pubid, title, appears_in, startpage, endpage
        FROM article AS a, publication AS p
        WHERE :pubid = appears_in
        AND p.pubid = a.pubid
        ORDER BY startpage;
*/

#line 82 "bibcontent.sqc"


    
/*
EXEC SQL OPEN articles;
*/

{
#line 84 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 84 "bibcontent.sqc"
  sqlaaloc(2,1,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 84 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 84 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 84 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 84 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 84 "bibcontent.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 84 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 84 "bibcontent.sqc"
  sqlastop(0L);
}

#line 84 "bibcontent.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 85 "bibcontent.sqc"

    for ( ;; ) {
        
/*
EXEC SQL FETCH articles INTO :pubid, :title, :appears_in, :startpage, :endpage;
*/

{
#line 87 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 87 "bibcontent.sqc"
  sqlaaloc(3,5,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 87 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 87 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 87 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 87 "bibcontent.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 26;
#line 87 "bibcontent.sqc"
      sql_setdlist[1].sqldata = (void*)title;
#line 87 "bibcontent.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 87 "bibcontent.sqc"
      sql_setdlist[2].sqltype = 496; sql_setdlist[2].sqllen = 4;
#line 87 "bibcontent.sqc"
      sql_setdlist[2].sqldata = (void*)&appears_in;
#line 87 "bibcontent.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 87 "bibcontent.sqc"
      sql_setdlist[3].sqltype = 496; sql_setdlist[3].sqllen = 4;
#line 87 "bibcontent.sqc"
      sql_setdlist[3].sqldata = (void*)&startpage;
#line 87 "bibcontent.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 87 "bibcontent.sqc"
      sql_setdlist[4].sqltype = 496; sql_setdlist[4].sqllen = 4;
#line 87 "bibcontent.sqc"
      sql_setdlist[4].sqldata = (void*)&endpage;
#line 87 "bibcontent.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 87 "bibcontent.sqc"
      sqlasetdata(3,0,5,sql_setdlist,0L,0L);
    }
#line 87 "bibcontent.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 87 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 87 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 87 "bibcontent.sqc"
  sqlastop(0L);
}

#line 87 "bibcontent.sqc"

        printf("Pubid: %d\n", pubid);
        printf("Type: ARTICLE\n");
        printf("Title: %s\n", title);

        
/*
EXEC SQL DECLARE authors CURSOR FOR
            SELECT name
            FROM author, wrote
            WHERE :pubid = publication
            AND aid = author
            ORDER BY name;
*/

#line 97 "bibcontent.sqc"


        
/*
EXEC SQL OPEN authors;
*/

{
#line 99 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 99 "bibcontent.sqc"
  sqlaaloc(2,1,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 99 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 496; sql_setdlist[0].sqllen = 4;
#line 99 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)&pubid;
#line 99 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 99 "bibcontent.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 99 "bibcontent.sqc"
  sqlacall((unsigned short)26,5,2,0,0L);
#line 99 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 99 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 99 "bibcontent.sqc"
  sqlastop(0L);
}

#line 99 "bibcontent.sqc"

        
/*
EXEC SQL WHENEVER NOT FOUND GO TO article;
*/

#line 100 "bibcontent.sqc"

        for ( ;; ) {
            
/*
EXEC SQL FETCH authors INTO :name;
*/

{
#line 102 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 102 "bibcontent.sqc"
  sqlaaloc(3,1,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 102 "bibcontent.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 11;
#line 102 "bibcontent.sqc"
      sql_setdlist[0].sqldata = (void*)name;
#line 102 "bibcontent.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 102 "bibcontent.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 102 "bibcontent.sqc"
  sqlacall((unsigned short)25,5,0,3,0L);
#line 102 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 102 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 102 "bibcontent.sqc"
  sqlastop(0L);
}

#line 102 "bibcontent.sqc"

            printf("Author: %s\n", name);
        }

article:
        
/*
EXEC SQL CLOSE authors;
*/

{
#line 107 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 107 "bibcontent.sqc"
  sqlacall((unsigned short)20,5,0,0,0L);
#line 107 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 107 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 107 "bibcontent.sqc"
  sqlastop(0L);
}

#line 107 "bibcontent.sqc"

        printf("In: %d\n", appears_in);
        printf("Pages: %d--%d\n", startpage, endpage);
        printf("\n");
    }

end:
    
/*
EXEC SQL CLOSE articles;
*/

{
#line 114 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 114 "bibcontent.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 114 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 114 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 114 "bibcontent.sqc"
  sqlastop(0L);
}

#line 114 "bibcontent.sqc"


    
/*
EXEC SQL COMMIT;
*/

{
#line 116 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 116 "bibcontent.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
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
    goto article;
  }
#line 116 "bibcontent.sqc"
  sqlastop(0L);
}

#line 116 "bibcontent.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 117 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 117 "bibcontent.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 117 "bibcontent.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 117 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 117 "bibcontent.sqc"
  sqlastop(0L);
}

#line 117 "bibcontent.sqc"

    exit(0);

error:
    printf("ERROR\n");
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 122 "bibcontent.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 124 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 124 "bibcontent.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
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

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 125 "bibcontent.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 125 "bibcontent.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 125 "bibcontent.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto article;
  }
#line 125 "bibcontent.sqc"
  sqlastop(0L);
}

#line 125 "bibcontent.sqc"

    exit(1);
}
