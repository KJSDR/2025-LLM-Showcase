#include <iostream>
#include <unordered_map>
#include <string>


void recommendService(const std::string& category) {
    std::unordered_map<std::string, std::string> recommendations = {
        {"web_analytics", "Consider using Plausible Analytics as an alternative to Google Analytics."},
        {"cloud_computing", "Explore Scaleway or OVHcloud for cloud computing services instead of AWS or Google Cloud."},
        {"email", "Try Mailfence or ProtonMail as alternatives to Gmail for email services."},
        {"search_engine", "Use Ecosia or Qwant as privacy-focused alternatives to Google Search."},
        {"navigation", "Check out Magic Earth as an alternative to Google Maps for navigation services."},
        {"file_hosting", "Consider Tresorit or Nextcloud for file hosting instead of Dropbox."},
        {"video_conferencing", "Explore Jitsi Meet as an alternative to Zoom for video conferencing."},
        {"document_collaboration", "Use CryptPad or ONLYOFFICE for collaborative document editing instead of Google Docs."},
        {"project_management", "Try OpenProject or Wekan as alternatives to Asana or Jira for project management."},
        {"music_streaming", "Consider using SoundCloud or Deezer as alternatives to Spotify or Apple Music."}
    };

    auto it = recommendations.find(category);
    if (it != recommendations.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "No recommendation available for the category: " << category << std::endl;
    }
}

int main() {
    std::string category;
    std::cout << "Enter the service category (e.g., web_analytics, cloud_computing, email): ";
    std::cin >> category;

    recommendService(category);

    return 0;
}
