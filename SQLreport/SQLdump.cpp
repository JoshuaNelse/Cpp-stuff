//
//  SQLdump.cpp
//  C++fibonacci
//
//  Created by josh shaver on 11/5/18.
//  Copyright © 2018 josh shaver. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>

int main(){
    std::system("cd /tmp");
    std::system("mysql -e \"select b.date,b.product,b.color,b.units,b.time,time/units as minutes_per_Unit from production as b where status = 'A' order by id desc\" -H  -u script -pMAKEFILE phptest > /tmp/dumpsql");
    std::system("mv /tmp/dumpsql /var/www/html/SQLreport.html");
    std::cout << "Go to 206.189.225.249/SQLreport.html to view the report" << std::endl;
    return 0;
}
