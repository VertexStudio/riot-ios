/*
 Copyright 2017 OpenMarket Ltd
 Copyright 2017 Vector Creations Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "ContactsDataSource.h"
#import "ContactTableViewCell.h"

@class ContactsTableViewController;

/**
 `ContactsTableViewController` delegate.
 */
@protocol ContactsTableViewControllerDelegate <NSObject>

/**
 Tells the delegate that the user selected a contact.
 
 @param contactsTableViewController the `ContactsTableViewController` instance.
 @param contact the selected contact.
 */
- (void)contactsTableViewController:(ContactsTableViewController *)contactsTableViewController didSelectContact:(MXKContact*)contact;

@end

/**
 'ContactsTableViewController' instance is used to display/filter a list of contacts.
 See 'ContactsTableViewController-inherited' object for example of use.
 */
@interface ContactsTableViewController : MXKViewController <UITableViewDelegate, MXKDataSourceDelegate>
{
@protected
    ContactsDataSource *contactsDataSource;
}

/**
 Returns the `UINib` object initialized for a `ContactsTableViewController`.
 
 @return The initialized `UINib` object or `nil` if there were errors during initialization
 or the nib file could not be located.
 */
+ (UINib *)nib;

/**
 Creates and returns a new `ContactsTableViewController` object.
 
 @discussion This is the designated initializer for programmatic instantiation.
 @return An initialized `ContactsTableViewController` object if successful, `nil` otherwise.
 */
+ (instancetype)contactsTableViewController;

/**
 The contacts table view.
 */
@property (weak, nonatomic) IBOutlet UITableView *contactsTableView;

/**
 If YES, the table view will scroll at the top on the next data source refresh.
 It comes back to NO after each refresh.
 */
@property (nonatomic) BOOL shouldScrollToTopOnRefresh;

/**
 The Google Analytics Instance screen name (Default is "ContactsTable").
 */
@property (nonatomic) NSString *screenName;

/**
 Refresh the cell selection in the table.
 
 This must be done accordingly to the currently selected contact in the master tabbar of the application.
 
 @param forceVisible if YES and if the corresponding cell is not visible, scroll the table view to make it visible.
 */
- (void)refreshCurrentSelectedCell:(BOOL)forceVisible;

/**
 Display the contacts described in the provided data source.
 
 Note1: The provided data source will replace the current data source if any. The caller
 should dispose properly this data source if it is not used anymore.
 
 @param listDataSource the data source providing the contacts list.
 */
- (void)displayList:(ContactsDataSource*)listDataSource;

/**
 Refresh the contacts table display.
 */
- (void)refreshContactsTable;

/**
 The delegate for the view controller.
 */
@property (nonatomic) id<ContactsTableViewControllerDelegate> contactsTableViewControllerDelegate;

@end

