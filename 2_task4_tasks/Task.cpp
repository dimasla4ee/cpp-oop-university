#include <iostream>

class Task {
   protected:
    std::string title = "";
    std::string description = "";
    bool isCompleted = false;

   public:
    Task(std::string title, std::string description, bool isCompleted)
            : title(title), description(description), isCompleted(isCompleted) {};

    void setTitle(std::string title) { this->title = title; };

    std::string getTitle() { return title; }

    void setDescription(std::string description) { this->description = description; };

    std::string getDescription() { return description; }

    void setIsCompleted(bool isCompleted) { this->isCompleted = isCompleted; };

    bool getIsCompleted() { return isCompleted; }

    void markAsCompleted() { isCompleted = true; };

    virtual void displayTaskDetails() const = 0;

    virtual ~Task() = default;
};

class SimpleTask : public Task {
   public:
    SimpleTask(std::string title, std::string description, bool isCompleted)
            : Task(title, description, isCompleted) {};

    void displayTaskDetails() const override {
        if (isCompleted) {
            std::cout << "- [x] ";
        } else {
            std::cout << "- [ ] ";
        }

        std::cout << title << std::endl << '\t' << description << std::endl;
    }
};

class DeadlineTask : public Task {
   private:
    std::string deadlineDate = "";

   public:
    DeadlineTask(std::string title, std::string description, bool isCompleted,
                 std::string deadlineDate)
            : Task(title, description, isCompleted), deadlineDate(deadlineDate) {};

    void displayTaskDetails() const override {
        if (isCompleted) {
            std::cout << "- [x] ";
        } else {
            std::cout << "- [ ] ";
        }

        std::cout << title << " | complete by " << deadlineDate << std::endl << '\t' << description
                  << std::endl;
    }
};

class PriorityTask : public Task {
   private:
    int priorityLevel;

   public:
    PriorityTask(std::string title, std::string description, bool isCompleted,
                 int priorityLevel)
            : Task(title, description, isCompleted), priorityLevel(priorityLevel) {};

    void displayTaskDetails() const override {
        if (isCompleted) {
            std::cout << "- [x] ";
        } else {
            std::cout << "- [ ] ";
        }

        std::cout << title << " | priority level: " << priorityLevel << std::endl << '\t'
                  << description << std::endl;
    }
};
