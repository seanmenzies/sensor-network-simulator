# Sensor Network Simulator

A modular C++ project that simulates a distributed sensor network with built-in cybersecurity features. Developed for learning and collaboration, this project models virtual sensors, a message broker, basic anomaly detection, and secure communication — with an optional frontend dashboard using Qt.

---

## 🔧 Features

- Virtual sensor nodes (e.g., temperature, motion) sending periodic data
- Central broker for routing and logging messages
- Modular CMake-based architecture
- Boost.Asio networking layer
- Optional Qt-based UI dashboard (frontend)
- Cybersecurity integration:
  - TLS encryption (OpenSSL)
  - Token-based authentication
  - Basic intrusion detection (replay/flood/spoof)

---

## 📁 Project Structure

sensor-network-simulator/
├── include/ # Shared headers
├── src/
│ ├── broker/ # Message broker logic
│ ├── sensors/ # Sensor simulation logic
│ ├── common/ # Shared utilities
│ ├── security/ # Authentication & encryption
│ └── frontend/ # Optional Qt-based dashboard
├── tests/ # Unit tests
├── build/ # Out-of-source build directory
├── TODO.md # Roadmap and milestones
├── README.md # Project overview
└── CMakeLists.txt # Root build script

yaml
Copy
Edit

---

## 🚀 Getting Started

### ✅ Prerequisites

Ensure the following packages are installed (Ubuntu example):

```bash
sudo apt update
sudo apt install build-essential cmake libboost-all-dev libssl-dev qtbase5-dev
🛠️ Build Instructions
From the project root:

bash
Copy
Edit
mkdir build
cd build
cmake ..
make
./sensor_sim```

🎯 Milestones
See TODO.md for the current development roadmap, including core features and cybersecurity goals.

🤝 Contributions
This is a learning-focused collaboration. If you're working on a module (e.g., security, frontend), open a branch or PR, or coordinate via issues.

📜 License
This project is open for educational use and experimentation. License to be decided.
