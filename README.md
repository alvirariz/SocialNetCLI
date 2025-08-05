# SocialNetCLI 

A console-based social network simulation built using C++ and object-oriented programming principles. This project was developed as an academic assignment, with a focus on modular design, dynamic memory management, and clean code structure.

---

##  Features

- **User Management:** Unique user profiles with friend lists and liked pages.
- **Page System:** Pages owned by users with shared posts and like counts.
- **Post System:** Text-based posts with optional activity metadata (e.g., "feeling happy").
- **Memory Sharing:** Repost older memories as new content.
- **Comments & Likes:** Users and pages can comment on and like posts (with limits).
- **Timeline View:** Posts from friends and liked pages in the last 24 hours.
- **Full Console I/O Interface:** Menu-driven, text-based interaction.
- **Dynamic Allocation:** Double pointers used for all object arrays, memory handled manually.

---

##  Project Structure

- `User` – Represents individual users with friends, posts, and liked pages.
- `Page` – Public-facing content entity with its own timeline.
- `Post` – Base class for content shared by users and pages.
- `Activity` – Optional metadata for posts (feeling, thinking, making, celebrating).
- `Memory` – Derived class referencing original post for memory sharing.
- `Comment` – Supports comments from users or pages.
- `SocialNetworkApp` – Master class handling all operations and control flow.

---

##  Technologies Used

- **Language:** C++
- **Environment:** Visual Studio (console project)
- **Concepts Applied:**
  - Object-Oriented Programming
  - Dynamic memory allocation
  - File I/O for initialization
  - Pointer-based relationships between classes

---

##  Sample Commands Implemented

- `Set current user`
- `View Home`
- `View Profile`
- `LikePost(postID)`
- `PostComment(postID, comment)`
- `ShareMemory(postID, caption)`
- `ViewLikedList(postID)`
- `ViewFriendList`
- `ViewPage(pageID)`

---

##  Objective

This project was designed to practice advanced OOP concepts in a practical, real-world inspired system. The original project required GUI implementation; however, this version focuses entirely on the backend logic and data relationships.

---

##  Notes

- No global variables or functions were used.
- All memory was dynamically allocated and properly deallocated.
- Arrays of objects were implemented using double pointers.
- The application runs entirely through a defined `Run()` function inside a manager class, maintaining separation of concerns.

---

##  Future Improvements

- **GUI Integration:** Replace CLI with a graphical interface using Qt or similar.
- **Code Refactor:** Use STL (`vector`, `map`) and polymorphism to reduce hardcoded logic.
- **Data Persistence:** Enable saving/loading app state via files or SQLite.
- **Input Validation:** Improve handling and error checks for cleaner user experience.


---

##  License

This project is released for educational and demonstration purposes only.

---

> Designed and developed by Alvira Rizwan.





