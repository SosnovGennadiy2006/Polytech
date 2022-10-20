//
// Created by Student on 17.10.2022.
//

#ifndef SRC_STYLESHEETSHELPER_H
#define SRC_STYLESHEETSHELPER_H

#include <QFile>
#include <QVector>

class StyleSheetsHelper {
public:
    static QString loadStyles(const QString& path)
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
        {
            return "";
        }
        return QLatin1String(file.readAll());
    }

    static QString mergeStyles(const QVector<QString>& files)
    {
        QString result;
        for (auto& elem : files)
        {
            result += loadStyles(elem);
        }
        return result;
    }
};

#endif //SRC_STYLESHEETSHELPER_H
