#ifndef FILEUTILS_HPP
# define FILEUTILS_HPP

# include <string>

typedef const std::string &t_strref;
typedef const char *const t_pchar;

std::string	openFileToString(t_pchar path);
std::string	replaceOccurence(t_strref content, t_pchar s1, t_pchar s2);
void		writeStringToFile(t_strref path, t_strref content);

#endif
