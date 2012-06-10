#include <my_global.h>
#include <my_sys.h>
#include <mysql.h>
#include <string.h>

static char *opt_host_name = "localhost";
static char *opt_user_name = "root";
static char *opt_password = "casacasa";
static unsigned int opt_port_num = 0;
static char *opt_socket_name = NULL;
static char *opt_db_name = "robust";
static unsigned int opt_flags = 0;

static MYSQL *conn;

int main(int argc, char **argv)
{
    char sql[60] = "update activity set state = 2 where id = ";
    char *id = NULL;
    if(argc == 1)
    {
        printf("it will set the state of activity to 2 by activity id.\nexample:turnActivityOver activity_id\nwhere activity_id is a number\n");
        exit(0);
    }
    conn = mysql_init(NULL);
    if(conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed.\n");
        exit(1);
    }
    if(mysql_real_connect(conn, opt_host_name, opt_user_name, opt_password, opt_db_name, opt_port_num, opt_socket_name, opt_flags)==NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    id = *(argv+1);
    strcat(sql, id);
    strcat(sql, ";");
    mysql_query(conn, sql);
    mysql_close(conn);
    exit(0);
}
