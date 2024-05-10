#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>

class DataManager {
public:
    static DataManager& instance() {
        static DataManager instance;
        return instance;
    }

    QString getString() const { return m_sharedString; }
    void setString(const QString& newString) { m_sharedString = newString; }

private:
    QString m_sharedString;

    // Private constructor to prevent external instantiation
    DataManager() = default;
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
};

#endif // DATAMANAGER_H
