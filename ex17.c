#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_DATA 512

struct Address
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database
{
    struct Address rows[MAX_ROWS];
};

struct Connection
{
    struct Database *db;
    FILE *file;
};

void die(char *message)
{
    printf("Aborting: %s\n", message);
    exit(1);
}

void Address_print(struct Address *address)
{
    printf("%d %s %s\n", address->id, address->name, address->email);
}

struct Connection *Database_open(char *filename, char action)
{
    struct Database *db = malloc(sizeof(struct Database));
    assert(db!=NULL);
    struct Connection *conn = malloc(sizeof(struct Connection));
    assert(conn!=NULL);

    conn->db = db;
    if(action== 'c')
    {
        conn->file = fopen(filename, "w");
    }
    else
    {
        conn->file = fopen(filename, "r+");
    }
    if(!conn->file)
    {
        die("Could not open file");
    }
    return conn;
}

void Database_create(struct Connection *conn)
{
    int i =0;
    for(i=0; i<MAX_ROWS; i++)
    {
        struct Address add = {.id=i, .set=0};
        conn->db->rows[i] = add;
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc!=1)
    {
        die("Failed to write db");
    }

    /*rc = fflush(conn->file);
    if(rc == -1)
    {
        die("Cannot flush db");
    }*/
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *address = &conn->db->rows[id];
    Address_print(address);
}

void Database_load(struct Connection *conn)
{
    int rt = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rt != 1)
    {
        die("Cannot read database from file\n");
    }
}
void Database_set(struct Connection *conn, int id, char *name, char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set)
    {
        die("already set.\n");
    }
    addr->set = 1;

    char *res = strncpy(addr->email, email, MAX_DATA);
    res = strncpy(addr->name, name, MAX_DATA);
    if(!res)
    {
        die("str copy failed");
    }
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Address *address;
    for(i=0; i<MAX_ROWS; i++)
    {
        address = &conn->db->rows[i];
        if(address->set)
        {
            Address_print(address);
        }
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id=0, .set=0};
    conn->db->rows[id] = addr;
}

void Database_close(struct Connection *conn)
{
    if(conn->file)
    {
        fclose(conn->file);
    }
    if(conn->db)
    {
        free(conn->db);
        free(conn);
    }
}

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        die("USAGE ./ex17 <filename> <action>");
    }

    char action = argv[2][0];

    struct Connection *conn = Database_open(argv[1], action);
    switch(action)
    {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;
        case 'r':
            if(argc!=4)
            {
                die("Usage: ./ex17 <filename> r <id>");
            }
            Database_load(conn);
            Database_get(conn, atoi(argv[3]));
            break;
        case 'd':
            if(argc!=4)
            {
                die("Usage: ./ex17 <filename> d <id>");
            }
            Database_load(conn);
            Database_delete(conn, atoi(argv[3]));
            Database_write(conn);
            break;
        case 's':
            if(argc!=6)
            {
                die("Usage: ./ex17 <filename> s <id> <name> <email>\n");
            }
            Database_load(conn);
            Database_set(conn, atoi(argv[3]), argv[4], argv[5]);
            Database_write(conn);
            break;
        case 'l':
            Database_load(conn);
            Database_list(conn);
            break;
    }

    Database_close(conn);
    return 0;
}
