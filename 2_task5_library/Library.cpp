#include <iostream>
#include <string>
#include <vector>

class LibraryItem {
   protected:
    std::string title = "";
    int publicationYear;
    std::string itemId;

   public:
    LibraryItem(std::string title, int publicationYear, std::string itemId)
            : title(title), publicationYear(publicationYear), itemId(itemId) {};

    void setTitle(const std::string &title) { this->title = title; }

    std::string getTitle() const { return title; }

    void setPublicationYear(int publicationYear) { this->publicationYear = publicationYear; }

    int getPublicationYear() const { return publicationYear; }

    void setItemId(const std::string &itemId) { this->itemId = itemId; }

    std::string getItemId() const { return itemId; }

    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() = default;
};

class Book : public LibraryItem {
   private:
    std::string author = "";
    std::string isbn = "";

   public:
    Book(std::string title, int publicationYear, std::string itemId,
         std::string author, std::string isbn)
            : LibraryItem(title, publicationYear, itemId), author(author), isbn(isbn) {};

    void displayDetails() const override {
        std::cout << itemId << ". " << author << " " << title << ". " << publicationYear
                  << ". ISBN: " << isbn << std::endl;
    }
};

class Magazine : public LibraryItem {
   private:
    int issueNumber;

   public:
    Magazine(std::string title, int publicationYear, std::string itemId, int issueNumber)
            : LibraryItem(title, publicationYear, itemId), issueNumber(issueNumber) {};

    void displayDetails() const override {
        std::cout << itemId << ". " << " " << title << ". " << publicationYear
                  << "№  " << issueNumber << std::endl;
    }
};

class Library {
   private:
    std::vector<LibraryItem *> items;
   public:
    void addItem(LibraryItem *item) { items.push_back(item); }

    void displayAllItems() const {
        for (auto item: items) {
            item->displayDetails();
        }
    }

    LibraryItem *findItem(const std::string &itemId) {
        for (auto item: items) {
            if (item->getItemId() == itemId) {
                return item;
            }
        }
        return nullptr;
    }

    ~Library() {
        items.clear();
        delete items;
    }
};
